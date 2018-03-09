/*********************************************************************
** Program Filename: assignment6.cpp
** Author: Alexander Nead-Work
** Date: 03/08/2018
** Description: Driver file for A6
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment6.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (!is_args_valid(argc, argv)) {
        printf("Invalid arguments specified.\n");
        printf("Usage: %s [size of board]; where [size of board] is 8, 10, or 12\n", argv[0]);
        return 1;
    }

    Piece** board;
    int size = SIZE;

    init_board(size, &board);
    print_board(size, board);

    delete_board(size, &board);

    return 0;
}