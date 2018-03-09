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
#define SIZE 12
#define BLACK_BG 40
#define WHITE_BG 47
#define BLACK_FG 30
#define RED_FG 31

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
    red = RED_FG,
    black = BLACK_FG
};

/**************************** structs ****************************/
struct Player {
    string name;
    Color color;
};

struct Piece {
    bool king;
    Color color;
    char symbol;
};

/**************************** functions ****************************/
void init_board(int, Piece***);
void print_board(int, Piece**);
void delete_board(int, Piece***);
bool is_args_valid(int, char**);

#endif