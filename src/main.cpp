#include "../includes/parse.hpp"
// #include "../includes/puzzle.hpp"

int     main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	try {
		Puzzle puzzle;
		puzzle = Parse::parseFile(av[1]);
		std::cout << "print puzzle: " << std::endl;
		puzzle.print();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "ok" << std::endl;
	return 0;
}
