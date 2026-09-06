#include "../includes/puzzle.hpp"

void Puzzle::print() const {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            printf("%3d ", _board[i * _size + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Puzzle::setSize(int const size) {
    this->_size = size;
}

void Puzzle::setBlankPos(int const blank_pos) {
    this->_blank_pos = blank_pos;
}

void Puzzle::setBoard(std::vector<int> const board) {
    this->_board = board;
}

int Puzzle::getSize() const {
    return (this->_size);
}

int Puzzle::getBlankPos() const {
    return (this->_blank_pos);
}

std::vector<int>    Puzzle::getBoard() const {
    return this->_board;
}

