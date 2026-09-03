#include "../includes/include.hpp"

int     main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	// BitcoinExchange exchange;

	// exchange.LoadDataBase("data.csv");
	// exchange.LoadInput(av[1]);

	std::cout << "ok" << std::endl;
	return 0;
}
