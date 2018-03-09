/*********************************************************************
** Program Filename: assignment6.cpp
** Author: Alexander Nead-Work
** Date: 03/08/2018
** Description: Driver file for A6
** Input: n/a
** Output: n/a
*********************************************************************/

/* box
    ╭───╮
    │   │
    ╰───╯
*/

#include "assignment6.hpp"

using namespace std;

int main() {
    Piece** board;
    init_board(&board);
    print_board(board);

    return 0;
}