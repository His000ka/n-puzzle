#include "../includes/parse.hpp"

std::vector<std::string> Parse::tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    std::string token;
    bool in_comment = false;

    for (size_t i = 0; i < line.length(); i++) {
        char c  = line[i];

        if (c == '#') {
            in_comment = true;
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            break ;
        }

        if (std::isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }
 
    return tokens;

}

//utils
bool isAllDigits(const std::string& str) {
    if (str.empty()) return false;

    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

void validatePuzzle(const Puzzle& puzzle) {
    int expected_size = puzzle.size * puzzle.size;
 
    //valid la taille
    if ((int)puzzle.board.size() != expected_size) {
        throw std::invalid_argument(
            "Error: expected " + std::to_string(expected_size) 
            + " numbers, got " + std::to_string(puzzle.board.size())
        );
    }


    //valid les valeurs du puzzle
    std::set<int>   seen;
    for (int num : puzzle.board) {
        if (num < 0 || num >= expected_size) {
            throw std::invalid_argument(
                "Error: number " + std::to_string(num) 
                + " out of range [0, " + std::to_string(expected_size - 1) + "]"
            );
        }
        if (seen.count(num)) {
            throw std::invalid_argument(
                "Error: duplicate number " + std::to_string(num)
            );

        }
        seen.insert(num);
    }

    //valid qu'il y est bien le 0
    if (!seen.count(0)) {
        throw std::invalid_argument("Error: missing 0 (blank space)");
    }

}

Puzzle Parse::parseFile(const std::string& filename) {
    std::ifstream    file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: cannot open file" + filename);
    }

    std::string line;
    int size = -1;
    std::vector<int> numbers;

    while (std::getline(file, line)) {
        std::vector<std::string> tokens = tokenize(line);
        if (tokens.empty()) continue;

        if (size == -1) {
            if (tokens.size() > 1) {
                throw std::invalid_argument(
                    "Error: size must be a single number (found " 
            + std::to_string(tokens.size()) + ")"
                );
            }
            if (!isAllDigits(tokens[0])) {
                throw std::invalid_argument(
                    "Error: '" + tokens[0] + "' is not a valid integer"
                );
            }
            try {
                size = std::stoi(tokens[0]);
                std::cout << tokens[0] << std::endl;
            } catch (const std::invalid_argument& e) {
                throw std::invalid_argument(
                    "Error: first number must be puzzle size"
                );
            } catch (const std::out_of_range& e) {
                throw std::invalid_argument(
                    "Error: size '" + tokens[0] + "' is too large"
                );
            }
            if (size < 2) {
                throw std::invalid_argument(
                    "Error: puzzle size must be at least 2"
                );

            }
        } else {
            for (const auto& token : tokens) {
                if (!isAllDigits(token)) {
                    throw std::invalid_argument(
                            "Error: '" + token + "' is not a valid integer"
                    );
                }
                try {
                    numbers.push_back(std::stoi(token));
                    std::cout << token + " ";
                } catch (const std::exception& e) {
                    throw std::invalid_argument(
                        "Error: invalid number '" + token + "'"
                    );
                }
            }
            std::cout << std::endl;
        }
    }
    file.close();
    if (size == -1) {
        throw std::invalid_argument(
            "Error: no valid puzzle size found in file"
        );
    }
    //creer le puzle;

    Puzzle puzzle(size);

    //def le puzzle;
    puzzle.board = numbers;


    for (int i = 0; i < (int)puzzle.board.size(); i++) {
        if (puzzle.board[i] == 0) {
            puzzle.blank_pos = i;
            break;
        }
    }
 
    if (puzzle.blank_pos == -1) {
        throw std::invalid_argument("Error: blank (0) not found");
    }

    validatePuzzle(puzzle);

    std::cout << "puzzle valide !" << std::endl;
    return puzzle;
}