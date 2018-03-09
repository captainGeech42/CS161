/*********************************************************************
** Program Filename: assignment_6func.cpp
** Author: Alexander Nead-Work
** Date: 03/08/2018
** Description: Function implementations for A6
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment6.hpp"

using namespace std;

void init_board(Piece*** board) {
    *board = new Piece*[SIZE];
    // printf("made inital array\n");
    for (int i = 0; i < SIZE; i++) {
        (*board)[i] = new Piece[SIZE];
        // printf("made new array @ i=%d\n", i);
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 == j % 2) {
                (*board)[i][j].symbol = 'X';
                (*board)[i][j].color = red;
            } else {
                (*board)[i][j].symbol = 'O';
                (*board)[i][j].color = black;
            }
            // printf("set [%d][%d] = %c\n", i, j, (*board)[i][j].symbol);
        }
    }
}

void print_board(Piece** board) {
    // print top border
    cout << '╭';
    for (int i = 0; i < SIZE * 2; i++) {
        cout << '─';
    }
    cout << '╮';
    cout << endl;

    // print pieces
    int bkgd;
    int frgd;
    for (int i = 0; i < SIZE; i++) {
        cout << '│';
        for (int j = 0; j < SIZE; j++) {
            // set colors
            frgd = board[i][j].color;
            if (i % 2 == j % 2) {
                bkgd = BLACK_BG;
            } else {
                bkgd = WHITE_BG;
            }

            // set the colors and print the piece
            printf("\033[%d;%dm%c", frgd, bkgd, board[i][j].symbol);

            cout << ' ';

            // reset the colors
            printf("\033[0m");
        }
        cout << '│';
        cout << endl;
    }

    // print bottom border
    cout << '╰';
    for (int i = 0; i < SIZE * 2; i++) {
        cout << '─';
    }
    cout << '╯';
    cout << endl;
}