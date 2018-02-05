/*********************************************************************
** Program Filename: assignment3_func.cpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Function implementations for A3
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment3.hpp"

using namespace std;

/*********************************************************************
** Function: check_range
** Description: Checks if a given value is within a defined range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-Conditions: integer values for the lower & upper bound, and the test value
** Post-Conditions: returns if the test value is in the range or not
*********************************************************************/ 
bool check_range(int lower_bound, int upper_bound, int test_value) {
	return test_value >= lower_bound && test_value <= upper_bound;
}

/*********************************************************************
** Function: is_int
** Description: Checks if a given string is a valid integer
** Parameters: string num
** Pre-Conditions: the string value
** Post-Conditions: returns if it is a valid integer
*********************************************************************/ 
bool is_int(string num) {
	if ((num[0] < 48 && num[0] != 45) || (num[0] > 57))
		return false;
	for (int i = 1; i < num.length(); i++) {
		if (!(num[i] >= 48 && num[i] <= 57 )) {
			return false;
		}
	}
	return true;
}

/*********************************************************************
** Function: is_float
** Description: Checks if a given string is a valid float
** Parameters: string num
** Pre-Conditions: the string value
** Post-Conditions: returns if it is a valid float
*********************************************************************/ 
bool is_float(string num) {
	if ((num[0] < 48 && num[0] != 45) || (num[0] > 57))
		return false;
	int decimal_counter = 0;
	for (int i = 1; i < num.length(); i++) {
		if (num[i] == 46) {
			decimal_counter++;
			if (decimal_counter > 1)
				return false;
		}
		else if (!(num[i] >= 48 && num[i] <= 57 )) {
			return false;
		}
	}
	if (decimal_counter == 0) {
		return false;
	}
	return true;
}

/*********************************************************************
** Function: is_capital
** Description: Checks if a given char is a capital letter
** Parameters: char letter
** Pre-Conditions: the char value
** Post-Conditions: returns if it is a capital letter
*********************************************************************/ 
bool is_capital(char letter) {
	return letter >= 65 && letter <= 90;
}

/*********************************************************************
** Function: is_even
** Description: Checks if a given integer is even
** Parameters: int num
** Pre-Conditions: the integer value
** Post-Conditions: returns if it is an even number
*********************************************************************/ 
bool is_even(int num) {
	return num % 2 == 0;
}

/*********************************************************************
** Function: is_odd
** Description: Checks if a given integer is odd
** Parameters: int num
** Pre-Conditions: the integer value
** Post-Conditions: returns if it is an odd number
*********************************************************************/ 
bool is_odd(int num) {
	return num % 2 == 1;
}

/*********************************************************************
** Function: equality_test
** Description: Describes the equality between two numbers
** Parameters: int num1, int num2
** Pre-Conditions: The two integers that are being tested
** Post-Conditions: The equality value
*********************************************************************/ 
int equality_test(int num1, int num2) {
	if (num1 < num2) {
		return -1;
	} else if (num1 == num2) {
		return 0;
	} else {
		return 1;
	}
}

/*********************************************************************
** Function: float_is_equal
** Description: Tests if two floats are equal to a given precision value
** Parameters: float num1, float num2, float precision
** Pre-Conditions: The two floats to compare and the precision value
** Post-Conditions: returns if it is equal or not
*********************************************************************/ 
bool float_is_equal(float num1, float num2, float precision) {
	float diff = abs(num1 - num2);
	return diff <= precision;
}

/*********************************************************************
** Function: numbers_present
** Description: Checks if a string has numbers in it
** Parameters: string sentence
** Pre-Conditions: The string to test
** Post-Conditions: returns if there are numbers present
*********************************************************************/ 
bool numbers_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 48 && sentence[i] <= 57) {
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: letters_present
** Description: Checks if a string has letters in it
** Parameters: string sentence
** Pre-Conditions: The string to test
** Post-Conditions: returns if there are letters present
*********************************************************************/ 
bool letters_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)) {
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: contains_sub_string
** Description: Checks if a given substring is in a given string
** Parameters: string sentence, string sub_string
** Pre-Conditions: The sentence and the substring (both strings)
** Post-Conditions: Whether or not the sentence contains the substring
*********************************************************************/ 
bool contains_sub_string(string sentence, string sub_string) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == sub_string[0]) {
			bool found_sub_string = true;
			for (int j = 0; j < sub_string.length(); j++) {
				if (sentence[i+j] != sub_string[j]) {
					found_sub_string = false;
					break;
				}
			}
			if (found_sub_string) {
				return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: word_count
** Description: Counts the number of words in a string
** Parameters: string sentence
** Pre-Conditions: The sentence
** Post-Conditions: returns the number of words
*********************************************************************/ 
int word_count(string sentence) {
	int num_words = 1;
	for (int i = 1; i < sentence.length(); i++) {
		if (sentence[i] == ' ' && sentence[i-1] != ' ')
			num_words++;
		if (i == sentence.length() && sentence[i] != ' ')
			num_words++;
	}
	return num_words;
}

/*********************************************************************
** Function: to_upper
** Description: Returns an all uppercase version of a string
** Parameters: string sentence
** Pre-Conditions: the string to uppercase
** Post-Conditions: returns an uppercase version of the string
*********************************************************************/ 
string to_upper(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 97 && sentence[i] <= 122) {
			sentence[i] -= 32;
		}
	}
	return sentence;
}

/*********************************************************************
** Function: to_lower
** Description: Returns an all lowercase version of a string
** Parameters: string sentence
** Pre-Conditions: the string to lowercase
** Post-Conditions: returns an lowercase version of the string
*********************************************************************/ 
string to_lower(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] += 32;
		}
	}
	return sentence;
}

/*********************************************************************
** Function: get_int
** Description: Gets a valid integer from the user
** Parameters: string prompt
** Pre-Conditions: The prompt for the user
** Post-Conditions: returns an int
*********************************************************************/ 
int get_int(string prompt) {
	bool valid_in = true;
	string in;
	do {
		if (!valid_in) {
			cout << "Invalid input received." << endl;
		}
		
		cout << prompt;
		getline(cin, in);

		valid_in = is_int(in);
	} while (!valid_in);

	//if we get to here, we have a valid int
	int newint = 0;
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == 48 || in[i] == 45) {
			continue;
		} else {
			newint += (in[i] - 48) * pow(10, in.length() - 1 - i);
		}
	}
	if (in[0] == 45)
		newint *= -1;
	return newint;
}

/*********************************************************************
** Function: get_float
** Description: Gets a valid float from the user
** Parameters: string prompt
** Pre-Conditions: The prompt for the user
** Post-Conditions: returns an float
*********************************************************************/ 
float get_float(string prompt) {
	bool valid_in = true;
	string in;
	int decimal_position;
	do {
		if (!valid_in) {
			cout << "Invalid input received." << endl;
		}

		cout << prompt;
		getline(cin, in);

		valid_in = is_float(in);
	} while (!valid_in);
	
	//if we get to here, we have a valid float
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == 46) {
			decimal_position = i;
			break;
		}
	}

	string integer = "";
	string decimal = "";
	for (int i = 0; i < decimal_position; i++) {
		integer += in[i];
	}
	for (int i = decimal_position+1; i < in.length(); i++) {
		decimal += in[i];
	}

	float num = 0;
	for (int i = 0; i < integer.length(); i++) {
		if (integer[i] == 48 || integer[i] == 45) {
			continue;
		} else {
			num += (integer[i] - 48) * pow(10, integer.length() - 1 - i);
		}
	}
	for (int i = 0; i < decimal.length(); i++) {
		if (decimal[i] == 48) {
			continue;
		} else {
			int power = -(1+i);
			num += (decimal[i] - 48) * pow(10, power);
		}
	}
	if (in[0] == 45) {
		num *= -1;
	}
	return num;
}

/*********************************************************************
** Function: get_header
** Description: Generates a nice header for outputting tests to the screen
** Parameters: string message
** Pre-Conditions: The message to be put in the header
** Post-Conditions: returns the header string
*********************************************************************/ 
string get_header(string message) {
	const int total_line_length = 80;
	const int message_length = message.length();
	int num_dashes = total_line_length - message_length - 2; //2 is the space buffer on either side of the message
	string output;
	
	int left_dash = num_dashes / 2;
	int right_dash;
	if (num_dashes % 2 == 1)
		right_dash = left_dash + 1;
	else
		right_dash = left_dash;

	output = string(left_dash, '-') + ' ' + message + ' ' + string(right_dash, '-');
	return output;
}