/*********************************************************************
** Program Filename: assignment5.hpp
** Author: Alexander Nead-Work
** Date: 02/26/2018
** Description: Header file for A5
** Input: n/a
** Output: n/a
*********************************************************************/

using namespace std;

#ifndef ASSIGNMENT5_HPP
#define ASSIGNMENT5_HPP

/**************************** definitions ****************************/

/**************************** includes ****************************/
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include "helper.hpp"

/**************************** structs ****************************/
struct player {
    int score;
    string name;
};

/**************************** functions ****************************/
int get_all_players(player**);
void roll_dice(int**);
bool is_game_over(int, player**);
player get_winner(int, player**);

#endif