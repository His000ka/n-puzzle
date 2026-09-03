#include "../includes/puzzle.hpp"

void Puzzle::print() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", board[i * size + j]);
        }
        printf("\n");
    }
    printf("\n");
}
