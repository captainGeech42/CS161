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
#define MAX_SCORE 10000

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
void print_scoreboard(int, player**);
int score_dice(int, int*);
bool is_triplet(int*, int);
bool is_double_triplet(int*);
bool is_pair(int*, int);
bool is_triple_pair(int*);
bool is_straight(int*);
bool is_six(int*);
int is_five(int*);
int is_four(int*);
bool is_four_and_pair(int*);
bool continue_rolling(bool, int);
void print_dice(int, int*);
int set_aside_dice(int, int*, int**);
string get_which_dice_aside(int, int*);
bool aside_is_valid(int, string, int*);
void reset_dice_array(int**);

#endif
