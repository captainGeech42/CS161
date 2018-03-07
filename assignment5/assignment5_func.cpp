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
    int num_players;
    bool good = true;
    do {
        if (!good) {
            cout << "Please enter a valid number." << endl;
        }
        num_players = get_int("Please enter the number of players (at least 2): ");
        good = num_players >= 2;
    } while (!good);

    *player_array = new player[num_players];

    string name;
    for (int i = 0; i < num_players; i++) {
        printf("Please enter the name for player %d: ", i + 1);
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
        if ((*dice_array)[i] != -1) {
            (*dice_array)[i] = (rand() % 6) + 1;
        }
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
        if ((*player_array)[i].score >= MAX_SCORE) {
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

void print_scoreboard(int num_players, player** player_array) {
    string line = string(20, '-');

    printf("Current Scores:\n%s\n", line.c_str());
    for (int i = 0; i < num_players; i++) {
        if ((*player_array)[i].score >= 500) {
            printf("%s\t%d\n", (*player_array)[i].name.c_str(), (*player_array)[i].score);
            printf("%s\n", line.c_str());
        }
    }
}

/*********************************************************************
** Function: score_dice
** Description: Determines the score for a roll
** Parameters: int num_dice, int** dice_array
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
int score_dice(int num_dice, int* dice_array) {
    // printf("scoring dice, num_dice=%d\n", num_dice);
    // int* dice_freq = new int[6];
    int dice_freq[6] = {0};
    for (int i = 0; i < num_dice; i++) {
        if (dice_array[i] > 0) {
            // printf("i=%d, dice_array[i]=%d, ", i, dice_array[i]);
            dice_freq[dice_array[i] - 1] += 1;
            // printf("frequency @ %d is %d\n", dice_array[i]-1, dice_freq[dice_array[i]-1]);            
        }
    }

    int score = 0;
    int retval = 0;

    // if (num_dice == 6) {
        // cout << "there are six dice" << endl;
        // two triplets = 2500pts
        score += 2500 * is_double_triplet(dice_freq);
        if (score > 0) return score;

        // four of a kind + pair = 1500pts
        score += 1500 * is_four_and_pair(dice_freq);
        if (score > 0) return score;

        // three pairs = 1500pts
        score += 1500 * is_triple_pair(dice_freq);
        if (score > 0) return score;

        // 1-6 straight = 1500pts
        score += 1500 * is_straight(dice_freq);
        if (score > 0) return score;

        // six of a kind = 3000pts
        score += 3000 * is_six(dice_freq);
        if (score > 0) return score;
        
    // } else {
        // five of a kind = 2000pts
        retval = is_five(dice_freq);
        // printf("is_five retval is %d\n", retval);
        if (retval >= 0) {
            // cout << "in is_five" << endl;
            score += 2000;
            dice_freq[retval] -= 5;
        }

        // four of a kind = 1000pts
        retval = is_four(dice_freq);
        // printf("is_four retval is %d\n", retval);
        if (retval >= 0) {
            // cout << "in is_four" << endl;
            score += 1000;
            dice_freq[retval] -= 4;
        }

        // three 6s = 600pts
        retval = is_triplet(dice_freq, 6);
        if (retval) {
            // cout << "in 6" << endl;
            score += 600;
            dice_freq[retval] -= 3;
        }

        // three 5s = 500pts
        retval = is_triplet(dice_freq, 5);
        if (retval) {
            // cout << "in 5" << endl;
            score += 500;
            dice_freq[retval] -= 3;
        }

        // three 4s = 400pts
        retval = is_triplet(dice_freq, 4);
        if (retval) {
            // cout << "in 4" << endl;
            score += 400;
            dice_freq[retval] -= 3;
        }

        // three 3s = 300pts
        retval = is_triplet(dice_freq, 3);
        if (retval) {
            // cout << "in 3" << endl;
            score += 300;
            dice_freq[retval] -= 3;
        }

        // three 2s = 200pts
        retval = is_triplet(dice_freq, 2);
        if (retval) {
            // cout << "in 2" << endl;
            score += 200;
            dice_freq[retval] -= 3;
        }

        // three 1s = 300pts
        retval = is_triplet(dice_freq, 1);
        if (retval) {
            // cout << "in 1" << endl;
            score += 300;
            dice_freq[retval] -= 3;
        }

        // single 5 = 50pts
        if (dice_freq[4] >= 1 && score == 0) {
            score += 50;
            dice_freq[4]--;
        }

        // single 1 = 100pts
        if (dice_freq[0] >= 1 && score == 0) {
            score += 100;
            dice_freq[0]--;
        }
    // }

    // delete[] dice_freq;
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
    return dice_freq[die - 1] == 3;
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
        num_triplets += is_triplet(dice_freq, i);
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
    return dice_freq[die - 1] == 2;
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
        num_pairs += is_pair(dice_freq, i);
    }
    return num_pairs == 3;
}

/*********************************************************************
** Function: is_straight
** Description: Determines if there is 1 through 6 present in the roll
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_straight(int* dice_freq) {
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] != 1) {
            return false;
        }
    }
    return true;
}

/*********************************************************************
** Function: is_six
** Description: Determines if there is a six of a kind
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_six(int* dice_freq) {
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] == 6) {
            // printf("IS_SIX: freq @ %d is 6\n", i);
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: is_five
** Description: Determines if there is a five of a kind
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
int is_five(int* dice_freq) {
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] == 5) {
            // printf("IS_FIVE: freq @ %d is 5\n", i);
            return i;
        }
    }
    return -1;
}

/*********************************************************************
** Function: is_four
** Description: Determines if there is a four of a kind
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
int is_four(int* dice_freq) {
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] == 4) {
            // printf("IS_FOUR: freq @ %d is 4\n", i);
            return i;
        }
    }
    return -1;
}

/*********************************************************************
** Function: is_four_and_pair
** Description: Determines if there is a four of a kind and a pair
** Parameters: int* dice_freq
** Pre-Conditions: dice_freq has ints in it
** Post-Conditions: none
*********************************************************************/
bool is_four_and_pair(int* dice_freq) {
    if (is_four(dice_freq) != 0) {
        return false;
    }
    bool pair = false;
    for (int i = 0; i < 6; i++) {
        if (dice_freq[i] != 4 && is_pair(dice_freq, i + 1))
            pair = true;
    }
    return pair;
}

/*********************************************************************
** Function: continue_rolling
** Description: Determines if the user wants/has to keep rolling
** Parameters: bool first_roll, int score
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool continue_rolling(bool first_roll, int score) {
    if (first_roll || score < 500)
        return true;

    return get_yes_no("Would you like to keep rolling ('yes' or 'no')? ");
}

/*********************************************************************
** Function: print_dice
** Description: Prints the value of the dice to the screen
** Parameters: int num_dice, int* dice_array
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
void print_dice(int num_dice, int* dice_array) {
    cout << "You rolled: " << endl;
    for (int i = 0; i < num_dice; i++) {
        if (dice_array[i] == -1)
            return;
        printf("Dice %d: %d\n", i + 1, dice_array[i]);
    }
}

/*********************************************************************
** Function: set_aside_dice
** Description: Sets aside the dice the user wants to be scored
** Parameters: int* dice_array, int** aside_dice
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
int set_aside_dice(int num_available, int* dice_array, int** aside_dice) {
    reset_dice_array(aside_dice);

    // int num_available = 0;
    // for (int i = 0; i < 6; i++) {
    //     if (dice_array[i] == -1)
    //         break;
    //     num_available++;
    // }

    string dice = get_which_dice_aside(num_available, dice_array);

    unsigned int i = 0;
    for (; i < dice.length(); i++) {
        (*aside_dice)[i] = dice_array[dice[i] - 48 - 1];
    }

    reset_dice_array(&dice_array);

    return i;
}

/*********************************************************************
** Function: get_which_dice_aside
** Description: Get the string of dice to set aside
** Parameters: int num_dice, int* dice_array
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
string get_which_dice_aside(int num_dice, int* dice_array) {
    string input;
    do {
        cout << "Please enter which dice to set aside." << endl;
        cout << "If you want dice 1, 2, and 4 set aside, please enter '124' (w/o quotes)." << endl;
        cout << "Dice: ";

        getline(cin, input);

        // if (input.length() == 0) {
        //     return input;
        // }
    } while (!aside_is_valid(num_dice, input, dice_array));

    return input;
}

/*********************************************************************
** Function: aside_is_valid
** Description: Determines if the aside dice string is valid
** Parameters: int num_dice, string input, int* dice_array
** Pre-Conditions: dice_array has ints in it
** Post-Conditions: none
*********************************************************************/
bool aside_is_valid(int num_dice, string input, int* dice_array) {
    int val;
    // printf("in aside_is_valid, num_dice=%d\n", num_dice);
    for (unsigned int i = 0; i < input.length(); i++) {
        val = input[i] - 48;
        // printf("in aside_is_valid, int is %d\n", val);
        if (val < 1 || val > num_dice) {
            cout << "Please enter a valid combination." << endl;
            return false;
        }
    }

    int* dice = new int[input.length()];
    for (unsigned int i = 0; i < input.length(); i++) {
        dice[i] = dice_array[input[i] - 1 - 48];
    }
    // cout << "CALLING SCORE IN VALID CHECK" << endl;
    if (score_dice(input.length(), dice) == 0) {
        cout << "Please enter a combination that scores points." << endl;
        return false;
    }
    // cout << "FINISHED SCORE IN VALID CHECK" << endl;
    delete[] dice;
    return true;
}

/*********************************************************************
** Function: reset_dice_array
** Description: Resets the contents of the dice array (sets all vals equal to 0)
** Parameters: int** array
** Pre-Conditions: none
** Post-Conditions: array will have a bunch of zeros
*********************************************************************/
void reset_dice_array(int** array) {
    for (int i = 0; i < 6; i++) {
        (*array)[i] = 0;
    }
}
