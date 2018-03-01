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

    while (!is_game_over(num_players, &player_array)) {
        player_array[0].score += 1000;
        cout << "maybe..." << endl;
    }   
}