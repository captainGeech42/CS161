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

void test() {
    int* dice = new int[6];
    dice[0] = 3;
    dice[1] = 6;
    // dice[2] = 3;
    // dice[3] = 4;
    // dice[4] = 3;
    // dice[5] = 1;

    printf("Your score is %d\n", score_dice(2, dice));
    delete[] dice;
}

/*********************************************************************
** Function: main
** Description: Runs the program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main() {
    // test();
    // return 0;

    srand(time(NULL));

    player* player_array;
    int num_players = get_all_players(&player_array);

    int* dice_array = new int[6];
    int* aside_dice = new int[6];

    int score;
    int roll_score;
    int turn_score;
    int potential_score;
    int current_player = 0;
    bool first_roll = true;
    bool farkle = false;
    int num_aside;
    while (!is_game_over(num_players, &player_array)) {
        // print current scoreboard
        print_scoreboard(num_players, &player_array);

        // print current player
        printf("It is now %s's turn.\n", player_array[current_player].name.c_str());

        // run the player's turn
        first_roll = true;
        farkle = false;
        num_aside = 0;
        turn_score = 0;
        score = player_array[current_player].score;
        while (continue_rolling(first_roll, turn_score+score)) {
            first_roll = false;
            roll_score = 0;

            // roll dice
            roll_dice(&dice_array);

            // output the dice roll
            print_dice(6-num_aside, dice_array);

            // check if it is a farkle
            // cout << "RUNNING FARKLE CHECK" << endl;
            potential_score = score_dice(6-num_aside, dice_array);
            // cout << "FINISHED FARKLE CHECK" << endl;
            if (potential_score == 0) {
                cout << "Farkle! Your turn is over, resulting in zero points for the turn" << endl;
                farkle = true;
                break;
            } else {
                // ask which dice to keep
                num_aside += set_aside_dice(6-num_aside, dice_array, &aside_dice);

                // score them
                roll_score = score_dice(num_aside, aside_dice);
                turn_score += roll_score;
                printf("Your current score for this round is: %d\n", turn_score);
                if (num_aside == 6) {
                    cout << "You've set aside all of the dice, so now you get to roll all 6 again!" << endl;
                    num_aside = 0;
                }
            }            
        }

        if (!farkle)
            player_array[current_player].score += turn_score;

        // switch to the next player
        if (current_player == num_players - 1)
            current_player = 0;
        else
            current_player++;
    }

    // // give each player one more turn if they aren't over 10k
    while (player_array[current_player].score < MAX_SCORE) {
        // print current scoreboard
        print_scoreboard(num_players, &player_array);

        // print current player
        printf("It is now %s's turn.\n", player_array[current_player].name.c_str());

        // run the player's turn
        first_roll = true;
        farkle = false;
        num_aside = 0;
        turn_score = 0;
        score = player_array[current_player].score;
        while (continue_rolling(first_roll, turn_score+score)) {
            first_roll = false;
            roll_score = 0;

            // roll dice
            roll_dice(&dice_array);

            // output the dice roll
            print_dice(6-num_aside, dice_array);

            // check if it is a farkle
            // cout << "RUNNING FARKLE CHECK" << endl;
            potential_score = score_dice(6-num_aside, dice_array);
            // cout << "FINISHED FARKLE CHECK" << endl;
            if (potential_score == 0) {
                cout << "Farkle! Your turn is over, resulting in zero points for the turn" << endl;
                farkle = true;
                break;
            } else {
                // ask which dice to keep
                num_aside += set_aside_dice(6-num_aside, dice_array, &aside_dice);

                // score them
                roll_score = score_dice(num_aside, aside_dice);
                turn_score += roll_score;
                printf("Your current score for this round is: %d\n", turn_score);
                if (num_aside == 6) {
                    cout << "You've set aside all of the dice, so now you get to roll all 6 again!" << endl;
                    num_aside = 0;
                }
            }            
        }

        if (!farkle)
            player_array[current_player].score += turn_score;

        // switch to the next player
        if (current_player == num_players - 1)
            current_player = 0;
        else
            current_player++;
    }
    // while (player_array[current_player].score < MAX_SCORE) {
    //     score = player_array[current_player].score;

    //     // print current scoreboard
    //     print_scoreboard(num_players, &player_array);

    //     // run the player's turn
    //     first_roll = true;
    //     while (continue_rolling(first_roll, score)) {
    //         // roll dice
    //         roll_dice(&dice_array);

    //         // output the dice roll
    //         print_dice(6-num_aside, dice_array);

    //         // ask which dice to keep
    //         num_aside = set_aside_dice(dice_array, &aside_dice);

    //         // score them
    //         roll_score = score_dice(num_aside, aside_dice);
    //         score += roll_score;

    //         if (roll_score == 0) {
    //             cout << "Farkle! Your turn is over, resulting in zero points for the turn" << endl;
    //             break;
    //         }
    //     }

    //     player_array[current_player].score = score;

    //     // switch to the next player
    //     if (current_player == num_players - 1)
    //         current_player = 0;
    //     else
    //         current_player++;
    // }

    // end the game
    player winner = get_winner(num_players, &player_array);

    printf("The winner is %s with %d points! GG WP\n", winner.name.c_str(), winner.score);

    delete[] player_array;
    delete[] dice_array;
    delete[] aside_dice;

    return 0;
}