#include "include.hpp"
#include "puzzle.hpp"

class Parse
{
	public:
		static Puzzle parseFile(const std::string& filename);
		// Parse(/* args */);
		// ~Parse();
	
	private:
		static std::vector<std::string> tokenize(const std::string& line);
};
