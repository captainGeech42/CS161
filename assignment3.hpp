/*********************************************************************
** Program Filename: assignment3.hpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Header file for A3
** Input: n/a
** Output: n/a
*********************************************************************/

using namespace std;

#ifndef ASSIGNMENT3_HPP
#define ASSIGNMENT3_HPP

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>

bool check_range(int lower_bound, int upper_bound, int test_value);
bool is_int(string num);
bool is_float(string num);
bool is_capital(char letter);
bool is_even(int num);
bool is_odd(int num);
int equality_test(int num1, int num2);
bool float_is_equal(float num1, float num2, float precision);
bool numbers_present(string sentence);
bool letters_present(string sentence);
bool contains_sub_string(string sentence, string sub_string);
int word_count(string sentence);
string to_upper(string sentence);
string to_lower(string sentence);
int get_int(string prompt);
float get_float(string prompt);
string get_header(string message);

#endif