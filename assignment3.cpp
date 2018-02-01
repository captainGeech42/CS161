/*********************************************************************
** Program Filename: assignment3.cpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Solution file for CS161 Assignment 2
** Input: Mostly none, a couple functions get string inputs via stdin
** Output: The results of various testing functions
*********************************************************************/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

bool check_range(int lower_bound, int upper_bound, int test_value) {
	return test_value >= lower_bound && test_value <= upper_bound;
}

bool is_int(string num) {
	for (int i = 0; i < num.length(); i++) {
		if (!((num[i] >= 48 && num[i] <= 57 ) || num[i] == 45)) {
			return false;
		}
	}
	return true;
}

bool is_float(string num) {
	for (int i = 0; i < num.length(); i++) {
		if (!((num[i] >= 48 && num[i] <= 57 ) || num[i] == 45 || num[i] == 46)) {
			return false;
		}
	}
	return true;
}

bool is_capital(char letter) {
	return letter >= 65 && letter <= 90;
}

bool is_even(int num) {
	return num % 2 == 0;
}

bool is_odd(int num) {
	return num % 2 == 1;
}

int equality_test(int num1, int num2) {
	if (num1 < num2) {
		return -1;
	} else if (num1 == num2) {
		return 0;
	} else {
		return 1;
	}
}

bool float_is_equal(float num1, float num2, float precision) {
	int num1i = num1 * pow(10, (int)precision);
	int num2i = num2 * pow(10, (int)precision);

	return num1i == num2i;
}

bool numbers_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 48 && sentence[i] <= 57) {
			return true;
		}
	}
	return false;
}

bool letters_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)) {
			return true;
		}
	}
	return false;
}

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

int word_count(string sentence) {
	int num_words = 1;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ') {
			num_words++;
		}
	}
	return num_words;
}

string to_upper(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 97 && sentence[i] <= 122) {
			sentence[i] -= 32;
		}
	}
	return sentence;
}

string to_lower(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] += 32;
		}
	}
	return sentence;
}

int get_int(string prompt) {
	bool valid_in = true;
	string in;
	do {
		if (!valid_in) {
			cout << "Invalid input received." << endl;
		}
		cout << prompt;
		getline(cin, in);

		valid_in = true;
		for (int i = 0; i < in.length(); i++) {
			if (!(in[i] >= 48 && in[i] <= 57) || in[i] == 45) {
				valid_in = false;
			}
		}
	} while (!valid_in);
	
	//if we get to here, we have a valid int
	istringstream iss(in);
	int int_in;
	iss >> int_in;
	return int_in;
}

int get_float(string prompt) {
	bool valid_in = true;
	string in;
	do {
		if (!valid_in) {
			cout << "Invalid input received." << endl;
		}
		cout << prompt;
		getline(cin, in);

		valid_in = true;
		for (int i = 0; i < in.length(); i++) {
			if (!(in[i] >= 48 && in[i] <= 57) || in[i] == 45 || in[i] == 46) {
				valid_in = false;
			}
		}
	} while (!valid_in);
	
	//if we get to here, we have a valid float
	istringstream iss(in);
	float float_in;
	iss >> float_in;
	return float_in;
}

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

int main() {
	const string pass = "PASS";
	const string fail = "FAIL";
	const string line = "------------------------------";
	
	/************************* check_range *************************/
	cout << get_header("Testing check_range") << endl;
	int lb = 1;
	int ub = 5;
	int good_test = 3;
	int bad_test = -3;
	bool check_range_true = check_range(lb, ub, good_test);
	bool check_range_false = check_range(lb, ub, bad_test);
	
	printf("Test 1: lower_bound = %d, upper_bound = %d, test_value = %d\n", lb, ub, good_test);
	cout << "Test 1 Status: ";
	if (check_range_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: lower_bound = %d, upper_bound = %d, test_value = %d\n", lb, ub, bad_test);
	cout << "Test 2 Status: ";
	if (!check_range_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
		
	/************************* is_int *************************/
	cout << line << " Testing is_int " << line << endl;
	string good_int = "1234";
	string bad_int = "12.34";
	bool is_int_true = is_int(good_int);
	bool is_int_false = is_int(bad_int);
	
	printf("Test 1: num = %s\n", good_int.c_str());
	cout << "Test 1 Status: ";
	if (is_int_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: num = %s\n", bad_int.c_str());
	cout << "Test 2 Status: ";
	if (!is_int_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
}