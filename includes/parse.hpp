#include "include.hpp"

class Parse
{
	public:
		static void parseFile(const std::string& filename);
		// Parse(/* args */);
		// ~Parse();
	
	private:
		static std::vector<std::string> tokenize(const std::string& line);
};
