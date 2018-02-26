/*********************************************************************
** Program Filename: assignment4.hpp
** Author: Alexander Nead-Work
** Date: 02/17/2018
** Description: Header file for A4
** Input: n/a
** Output: n/a
*********************************************************************/

using namespace std;

#ifndef ASSIGNMENT4_HPP
#define ASSIGNMENT4_HPP

#define NUMBER 0
#define OPERATOR 1
#define SPACE 2
#define DO_MATH 3

#define OP1 0
#define OP2 1

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

int get_mode();
bool is_valid_mode(string);

void standard_calculator();
string get_standard_calculator_input();
float string_to_float(string);

void decimal_to_binary();
int get_decimal_binary_input();
bool is_unsigned_int(string);

void binary_to_decimal();
string get_binary_decimal_input();
bool is_binary(string);

void grade_calculator();
float weighted_average();
float unweighted_average();
int get_int(string);
float get_float(string);
bool is_int(string);
bool is_float(string);
bool is_valid_grade(string);
bool are_valid_grades(string);
string append_int_to_string(string, int);
string get_grades(string);
int word_count(string);
int add_up_grades(string);

#endif