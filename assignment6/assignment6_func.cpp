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

/*********************************************************************
** Function: init_board
** Description: Initalizes the game board
** Parameters: int size, Piece*** board
** Pre-Conditions: size is a valid size (8, 10, or 12)
** Post-Conditions: makes a 2D array of Pieces @ *&board
*********************************************************************/
void init_board(int size, Piece*** board) {
    *board = new Piece*[size];
    for (int i = 0; i < size; i++) {
        (*board)[i] = new Piece[size];
        for (int j = 0; j < size; j++) {
            if (i % 2 == j % 2) {
                (*board)[i][j].symbol = 'X';
                (*board)[i][j].color = red;
            } else {
                (*board)[i][j].symbol = 'O';
                (*board)[i][j].color = black;
            }
        }
    }
}

/*********************************************************************
** Function: print_board
** Description: Prints out the board
** Parameters: int size, Piece** board
** Pre-Conditions: size is a valid size (8, 10, or 12) and board has been initialized
** Post-Conditions: none
*********************************************************************/
void print_board(int size, Piece** board) {
    // print column labels
    if (size < 10) {
        cout << "  ";
    } else {
        cout << "   ";
    }
    for (int i = 'a'; i < 'a' + size; i++) {
        printf("%c ", i);
    }
    cout << endl;

    // print top border
    if (size < 10) {
        cout << " ";
    } else {
        cout << "  ";
    }
    cout << "╭";
    for (int i = 0; i < size * 2; i++) {
        cout << "─";
    }
    cout << "╮";
    cout << endl;

    // print pieces
    int bkgd;
    int frgd;
    for (int i = 0; i < size; i++) {
        if (size >= 10) {
            if (i + 1 < 10) {
                printf(" %d│", 1 + i);
            } else {
                printf("%d│", 1 + i);
            }
        } else {
            printf("%d│", 1 + i);
        }
        for (int j = 0; j < size; j++) {
            // set colors
            frgd = board[i][j].color;
            if (i % 2 == j % 2) {
                bkgd = BLACK_BG;
            } else {
                bkgd = WHITE_BG;
            }

            // set the colors and print the piece
            printf("\033[%d;%dm%c ", frgd, bkgd, board[i][j].symbol);

            // reset the colors
            printf("\033[0m");
        }
        cout << "│";
        cout << endl;
    }

    // print bottom border
    if (size < 10) {
        cout << " ";
    } else {
        cout << "  ";
    }
    cout << "╰";
    for (int i = 0; i < size * 2; i++) {
        cout << "─";
    }
    cout << "╯";
    cout << endl;
}

/*********************************************************************
** Function: delete_board
** Description: Frees the memory used to store the board
** Parameters: int size, Piece*** board
** Pre-Conditions: size is a valid size (8, 10, or 12) and board has been initialized
** Post-Conditions: *board will not have any data
*********************************************************************/
void delete_board(int size, Piece*** board) {
    for (int i = 0; i < size; i++) {
        delete[] (*board)[i];
    }

    delete[] *board;
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool is_args_valid(int argc, char** argv) {
    if (argc != 2) {
        return false;
    }

    char* length = argv[1];
    return (strcmp("8", length) == 0 || strcmp("10", length) == 0 || strcmp("12", length) == 0);
}

/*********************************************************************
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/