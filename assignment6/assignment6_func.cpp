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
** Parameters: Gameboard* gameboard
** Pre-Conditions: gameboard->size is a valid size (8, 10, or 12)
** Post-Conditions: makes a 2D array of Pieces @ gameboard->board
*********************************************************************/
void init_board(Gameboard* gameboard) {
    const int rows_per_player = gameboard->size / 2 - 1;

    gameboard->board = new Piece*[gameboard->size];
    for (int i = 0; i < gameboard->size; i++) {
        gameboard->board[i] = new Piece[gameboard->size];
        for (int j = 0; j < gameboard->size; j++) {
            gameboard->board[i][j].exists = false;
            gameboard->board[i][j].king = false;
            gameboard->board[i][j].selected = false;
            if (i < rows_per_player && !(i % 2 == j % 2)) {
                gameboard->board[i][j].color = kRed;
                gameboard->board[i][j].exists = true;
            } else if (i >= gameboard->size - rows_per_player && !(i % 2 == j % 2)) {
                gameboard->board[i][j].color = kWhite;
                gameboard->board[i][j].exists = true;
            }
        }
    }
}

/*********************************************************************
** Function: print_board
** Description: Prints out the board
** Parameters: Gameboard gameboard
** Pre-Conditions: gameboard.size is a valid size (8, 10, or 12) and gameboard.board has been initialized
** Post-Conditions: none
*********************************************************************/
void print_board(Gameboard gameboard) {
    // print column labels
    if (gameboard.size < 10) {
        cout << "  ";
    } else {
        cout << "   ";
    }
    for (int i = 'a'; i < 'a' + gameboard.size; i++) {
        printf("%c ", i);
    }
    cout << endl;

    // print top border
    if (gameboard.size < 10) {
        cout << " ";
    } else {
        cout << "  ";
    }
    cout << "╭";
    for (int i = 0; i < gameboard.size * 2; i++) {
        cout << "─";
    }
    cout << "╮";
    cout << endl;

    int bkgd;
    char symbol;
    Piece piece;
    for (int i = 0; i < gameboard.size; i++) {
        // print row labels
        if (gameboard.size >= 10) {
            if (i + 1 < 10) {
                printf(" %d│", 1 + i);
            } else {
                printf("%d│", 1 + i);
            }
        } else {
            printf("%d│", 1 + i);
        }

        // print pieces
        for (int j = 0; j < gameboard.size; j++) {
            piece = gameboard.board[i][j];
            // set colors
            if (i % 2 == j % 2) {
                bkgd = WHITE_BG;
            } else {
                bkgd = BLACK_BG;
            }

            // set the symbol
            if (piece.exists) {
                if (piece.king) {
                    symbol = KING;
                } else {
                    symbol = PIECE;
                }
            } else {
                symbol = ' ';
            }

            // set the colors and print the piece
            printf("\033[%d;%dm%c ", piece.selected ? SELECTED : piece.color, bkgd, symbol);

            // reset the colors
            printf("\033[0m");
        }
        cout << "│";
        cout << endl;
    }

    // print bottom border
    if (gameboard.size < 10) {
        cout << " ";
    } else {
        cout << "  ";
    }
    cout << "╰";
    for (int i = 0; i < gameboard.size * 2; i++) {
        cout << "─";
    }
    cout << "╯";
    cout << endl;
}

/*********************************************************************
** Function: delete_board
** Description: Frees the memory used to store the board
** Parameters: Gameboard* gameboard
** Pre-Conditions: gameboard->size is a valid size (8, 10, or 12) and gameboard->board has been initalized
** Post-Conditions: gameboard->board will not have any data
*********************************************************************/
void delete_board(Gameboard* gameboard) {
    for (int i = 0; i < gameboard->size; i++) {
        delete[] gameboard->board[i];
    }

    delete[] gameboard->board;
}

/*********************************************************************
** Function: is_args_valid
** Description: int argc, char** argv
** Parameters: checks if the given program args are valid
** Pre-Conditions: argc is a valid length, argv has been filled with data
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
** Function: is_game_over
** Description: Checks if the game is over for a given color
** Parameters: Color color, Gameboard gameboard
** Pre-Conditions: gameboard.size is a valid size (8, 10, or 12) and gameboard.board has been initialized
** Post-Conditions: none
*********************************************************************/
bool is_game_over(Color color, Gameboard gameboard) {
    return true;
}

/*********************************************************************
** Function: is_coord_valid
** Description: Checks if a given coordinate is valid on the mode and player
** Parameters: Coordinate coord, Player player, Gameboard gameboard, CoordinateSelectionMode mode
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool is_coord_valid(Coordinate coord, Player player, Gameboard gameboard, CoordinateSelectionMode mode) {
    if (strlen(coord.col) != 1) {
        return false;
    }

    int row = get_row(coord);
    int col = get_col(coord);

    if (!(row < gameboard.size && col < gameboard.size)) {
        return false;
    }

    // if we get to this point, our coordinate exists on the board
    // make sure it is valid for the specified mode
    Piece piece = gameboard.board[row][col];
    switch (mode) {
    case kPiece:
        // make suere there is a piece of the correct color at the desired location
        if (piece.exists && piece.color == player.color) {
            return true;
        }
        // TODO make sure there are valid moves for that piece
        break;
    case kLocation:
        // make sure there isn't a piece at the desired location
        if (!piece.exists) {
            return true;
        }
        // TODO make sure we can move a piece there
        break;
    }

    return false;
}

/*********************************************************************
** Function: get_row
** Description: Returns the zero-based integer for the row
** Parameters: Coordinate coord
** Pre-Conditions: coord is valid
** Post-Conditions: none
*********************************************************************/
int get_row(Coordinate coord) {
    return parse_int(coord.row) - 1;
}

/*********************************************************************
** Function: get_col
** Description: Returns the zero-based integer for the column
** Parameters: Coordinate coord
** Pre-Conditions: coord is valid
** Post-Conditions: none
*********************************************************************/
int get_col(Coordinate coord) {
    return coord.col[0] - 'a';
}

/*********************************************************************
** Function: get_coord
** Description: Get a valid coordinate for the given mode and player
** Parameters: Player player, Gameboard gameboard, CoordinateSelectionMode mode
** Pre-Conditions: Player is valid, gameboard is valid
** Post-Conditions: none
*********************************************************************/
Coordinate get_coord(Player player, Gameboard gameboard, CoordinateSelectionMode mode) {
    Coordinate coord;
    coord.row = 0;
    coord.col = 0;
    return coord;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/