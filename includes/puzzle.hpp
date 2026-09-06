#include "include.hpp"

class Puzzle
{
    public:

        Puzzle() : _size(0), _blank_pos(-1) {}
            Puzzle(int n) : _size(n), _blank_pos(-1) {
                _board.resize(n * n);
            }

        void print() const;

        void setSize(int const size);
        void setBlankPos(int const blank_pos);
        void setBoard(std::vector<int> const board);

        int getSize() const;
        int getBlankPos() const;
        std::vector<int>    getBoard() const;

    private:
        int _size;
        std::vector<int>	_board;
        int	_blank_pos;
    };
