/*********************************************************************
** Program Filename: assignment6.cpp
** Author: Alexander Nead-Work
** Date: 03/08/2018
** Description: Driver file for A6
** Input: size of the board (valid options are 8, 10, and 12)
** Output: n/a
*********************************************************************/

#include "assignment6.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (!is_args_valid(argc, argv)) {
        fprintf(stderr, "Invalid arguments specified.\n");
        fprintf(stderr, "Usage: %s [size of board]; where [size of board] is 8, 10, or 12\n", argv[0]);
        return 1;
    }

    Gameboard gameboard;
    gameboard.size = parse_int(argv[1]);

    init_board(&gameboard);
    print_board(gameboard);
    gameboard.board[3][2].selected = true;
    gameboard.board[9][2].selected = true;
    print_board(gameboard);

    delete_board(&gameboard);

    return 0;
}