/*********************************************************************
** Program Filename: assignment_5func.cpp
** Author: Alexander Nead-Work
** Date: 02/26/2018
** Description: Function implementations for A5
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment5.hpp"

using namespace std;

/*********************************************************************
** Function: get_all_players
** Description: Builds an array of all the players
** Parameters: player** player_array
** Pre-Conditions: none
** Post-Conditions: makes an array of players @ player_array
*********************************************************************/
int get_all_players(player** player_array) {
    int num_players = get_int("Please enter the number of players: ");
    *player_array = new player[num_players];

    string name;
    for (int i = 0; i < num_players; i++) {
        printf("Please enter the name for player %d: ", i+1);
        getline(cin, name);
        (*player_array)[i].name = name;
        (*player_array)[i].score = 0;
    }

    return num_players;
}

/*********************************************************************
** Function: roll_dice
** Description: Rolls the dice
** Parameters: int** dice_array
** Pre-Conditions: dice_array has been initalized
** Post-Conditions: none
*********************************************************************/
void roll_dice(int** dice_array) {
    for (int i = 0; i < 6; i++) {
        (*dice_array)[i] = (rand() % 6) + 1;
    }
}

/*********************************************************************
** Function: is_game_over
** Description: Checks if anybody is over 10k points
** Parameters: int num_players, player** player_array
** Pre-Conditions: player_array has players in it
** Post-Conditions:
*********************************************************************/
bool is_game_over(int num_players, player** player_array) {
    for (int i = 0; i < num_players; i++) {
        if ((*player_array)[i].score >= 10000) {
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: get_winner
** Description: Checks if anybody is over 10k points
** Parameters: int num_players, player** player_array
** Pre-Conditions: player_array has players in it
** Post-Conditions: none
*********************************************************************/
player get_winner(int num_players, player** player_array) {

}

