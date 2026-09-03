#include "../includes/parse.hpp"

int     main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	try {
		Parse::parseFile(av[1]);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "ok" << std::endl;
	return 0;
}
