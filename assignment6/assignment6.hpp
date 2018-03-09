/*********************************************************************
** Program Filename: assignment6.hpp
** Author: Alexander Nead-Work
** Date: 03/08/2018
** Description: Header file for A6
** Input: n/a
** Output: n/a
*********************************************************************/

using namespace std;

#ifndef ASSIGNMENT6_HPP
#define ASSIGNMENT6_HPP

/**************************** definitions ****************************/
// color codes were obtained from https://en.wikipedia.org/wiki/ANSI_escape_code#3/4_bit
#define BLACK_BG 40
#define WHITE_BG 47
#define WHITE_FG 37
#define RED_FG 31
#define SELECTED 32

#define PIECE 'o'
#define KING 'k'

/**************************** includes ****************************/
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include "helper.hpp"

/**************************** enums ****************************/
enum Color {
    kRed = RED_FG,
    kWhite = WHITE_FG
};

enum CoordinateSelectionMode {
    kPiece = 1,
    kLocation = 2
};

/**************************** structs ****************************/
struct Player {
    string name;
    Color color;
};

struct Piece {
    bool exists;
    bool king;
    bool selected;
    Color color;
};

struct Gameboard {
    int size;
    Piece** board;
};

struct Coordinate {
    char* row;
    char* col;
};

/**************************** functions ****************************/
void init_board(Gameboard*);
void print_board(Gameboard);
void delete_board(Gameboard*);
bool is_args_valid(int, char**);
bool is_game_over(Color color, Gameboard);
bool is_coord_valid(Coordinate, Player, Gameboard, CoordinateSelectionMode);
int get_row(Coordinate);
int get_col(Coordinate);
Coordinate get_coord(Player, Gameboard, CoordinateSelectionMode);
bool is_move_valid(Coordinate, Player);

#endif