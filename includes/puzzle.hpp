#include "include.hpp"

class Puzzle 
{
    public:
        int size;
        std::vector<int>	board;
		int	blank_pos;
        
        Puzzle() : size(0), blank_pos(-1) {}
        Puzzle(int n) : size(n), blank_pos(-1) {
            board.resize(n * n);
        }

        void print() const;
    
    private:
        /* data */
};