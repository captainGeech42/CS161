/*********************************************************************
** Program Filename: assignment5.cpp
** Author: Alexander Nead-Work
** Date: 02/26/2018
** Description: Driver file for A5
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment5.hpp"

using namespace std;

/*********************************************************************
** Function: main
** Description: Runs the program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main() {
    srand(time(NULL));

    player* player_array;
    int num_players = get_all_players(&player_array);

    int* dice_array = new int[6];

    int score;
    int current_player = 0;
    while (!is_game_over(num_players, &player_array)) {
        score = 0;

        // run the player's turn
        

        // switch to the next player
        if (current_player == num_players - 1)
            current_player = 0;
        else
            current_player++;
    }

    return 0;
}