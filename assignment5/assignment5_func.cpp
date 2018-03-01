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
    int index;
    int high_score = 0;
    int score;
    for (int i = 0; i < num_players; i++) {
        score = (*player_array)[i].score;
        if (score > high_score) {
            high_score = score;
            index = i;
        }
    }
    return (*player_array)[index];
}

/*********************************************************************
** Function: score_dice
** Description: Determines the score for a roll
** Parameters: int num_dice, int** dice_array
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
int score_dice(int num_dice, int** dice_array) {
    int* dice_freq[6] = {0};
    for (int i = 0; i < num_dice; i++) {
        dice_freq[(*dice_array)[i]-1] += 1;
    }

    int score = 0;

    // two triplets = 2500pts
    score += 2500 * is_double_triplet(*dice_freq);
    return score;

    // four of a kind + pair = 1500pts

    // three pairs = 1500pts
    score += 1500 * is_triple_pair(*dice_freq);
    return score;

    // 1-6 straight = 1500pts
    score += 1500 * is_straight(*dice_freq);

    // six of a kind = 3000pts

    // five of a kind = 2000pts

    // four of a kind = 1000pts

    // three 6s = 600pts
    score += 600 * is_triplet(*dice_freq, 6);

    // three 5s = 500pts
    score += 500 * is_triplet(*dice_freq, 5);

    // three 4s = 400pts
    score += 400 * is_triplet(*dice_freq, 4);

    // three 3s = 300pts
    score += 300 * is_triplet(*dice_freq, 3);

    // three 2s = 200pts
    score += 200 * is_triplet(*dice_freq, 2);

    // three 1s = 300pts
    score += 300 * is_triplet(*dice_freq, 1);

    // single 5 = 50pts
    if ((*dice_freq)[4] == 1) {
        score += 50;
        dice_freq[4]--;
    }

    // single 1 = 100pts
    if ((*dice_freq)[0] == 1) {
        score += 100;
        dice_freq[0]--;
    }

    return score;
}

/*********************************************************************
** Function: is_triplet
** Description: Determines if the given die face is a triplet
** Parameters: int* dice_freq, int die
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_triplet(int* dice_freq, int die) {
    return dice_freq[die-1] == 3;
}

/*********************************************************************
** Function: is_double_triplet
** Description: Determines if there are two triplets in the dice roll
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_double_triplet(int* dice_freq) {
    int num_triplets = 0;
    for (int i = 1; i <= 6; i++) {
        num_triplets += is_triplet(*&dice_freq, i);
    }
    return num_triplets == 2;
}

/*********************************************************************
** Function: is_pair
** Description: Determines if the given die face is a pair
** Parameters: int* dice_freq, int die
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_pair(int* dice_freq, int die) {
    return dice_freq[die-1] == 2;
}

/*********************************************************************
** Function: is_triple_pair
** Description: Determines if there are three pairs in the dice roll
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_triple_pair(int* dice_freq) {
    int num_pairs = 0;
    for (int i = 1; i <= 6; i++) {
        num_pairs += is_pair(*&dice_freq, i);
    }
    return num_pairs == 3;
}

bool is_straight(int* dice_freq) {
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] != 1) {
            return false;
        }
    }
    return true;
}