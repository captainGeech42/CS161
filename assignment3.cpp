/*********************************************************************
** Program Filename: assignment3.cpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Solution file for CS161 Assignment 3
** Input: Mostly none, a couple functions get string inputs via stdin
** Output: The results of various testing functions
*********************************************************************/

#include "assignment3.hpp"

using namespace std;

int main() {
	const string pass = "PASS";
	const string fail = "FAIL";
	
	/************************* check_range *************************/
	cout << get_header("Testing check_range") << endl;
	int lb = 1;
	int ub = 5;
	int good_test = 3;
	int bad_test = -3;
	bool check_range_true = check_range(lb, ub, good_test);
	bool check_range_false = check_range(lb, ub, bad_test);
	
	printf("Test 1: lower_bound = %d, upper_bound = %d, test_value = %d\n", lb, ub, good_test);
	printf("Expected Output: %d\nActual Output %d\n", 1, check_range_true);
	cout << "Test 1 Status: ";
	if (check_range_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: lower_bound = %d, upper_bound = %d, test_value = %d\n", lb, ub, bad_test);
	printf("Expected Output: %d\nActual Output %d\n", 0, check_range_false);
	cout << "Test 2 Status: ";
	if (!check_range_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
		
	/************************* is_int *************************/
	cout << get_header("Testing is_int") << endl;
	string good_int = "1234";
	string decimal_int = "12.34";
	string letter_int = "12asdf";
	string oneneg_int = "-1234";
	string twoneg_int = "--5678";
	bool is_int_true = is_int(good_int);
	bool is_int_decimal = is_int(decimal_int);
	bool is_int_letter = is_int(letter_int);
	bool is_int_oneneg = is_int(oneneg_int);
	bool is_int_twoneg = is_int(twoneg_int);
	
	printf("Test 1: num = \"%s\"\n", good_int.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 0, is_int_true);
	cout << "Test 1 Status: ";
	if (is_int_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: num = \"%s\"\n", decimal_int.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, is_int_decimal);
	cout << "Test 2 Status: ";
	if (!is_int_decimal)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 3: num = \"%s\"\n", letter_int.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, is_int_letter);
	cout << "Test 3 Status: ";
	if (!is_int_letter)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 4: num = \"%s\"\n", oneneg_int.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, is_int_oneneg);
	cout << "Test 4 Status: ";
	if (is_int_oneneg)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 5: num = \"%s\"\n", twoneg_int.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, is_int_twoneg);
	cout << "Test 5 Status: ";
	if (!is_int_twoneg)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* is_float *************************/
	cout << get_header("Testing is_float") << endl;
	string good_float = "12.34";
	string bad_float = "12.34asdf";
	bool is_float_true = is_float(good_float);
	bool is_float_false = is_float(bad_float);

	printf("Test 1: num = \"%s\"\n", good_float.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 0, is_float_true);
	cout << "Test 1 Status: ";
	if (is_float_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: num = \"%s\"\n", bad_float.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, is_float_false);
	cout << "Test 2 Status: ";
	if (!is_float_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* is_capital *************************/
	cout << get_header("Testing is_capital") << endl;
	char good_char = 'B';
	char bad_char = 'b';
	bool is_capital_true = is_capital(good_char);
	bool is_capital_false = is_capital(bad_char);

	printf("Test 1: letter = %c\n", good_char);
	printf("Expected Output: %d\nActual Output %d\n", 0, is_capital_true);
	cout << "Test 1 Status: ";
	if (is_capital_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: letter = %c\n", bad_char);
	printf("Expected Output: %d\nActual Output %d\n", 1, is_capital_false);
	cout << "Test 2 Status: ";
	if (!is_capital_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* is_even *************************/
	cout << get_header("Testing is_even") << endl;
	int good_even = 4;
	int bad_even = 5;
	bool is_even_true = is_even(good_even);
	bool is_even_false = is_even(bad_even);

	printf("Test 1: num = %d\n", good_even);
	printf("Expected Output: %d\nActual Output %d\n", 0, good_even);
	cout << "Test 1 Status: ";
	if (is_even_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: num = %d\n", bad_even);
	printf("Expected Output: %d\nActual Output %d\n", 1, bad_even);
	cout << "Test 2 Status: ";
	if (!is_even_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* is_odd *************************/
	cout << get_header("Testing is_odd") << endl;
	int good_odd = 5;
	int bad_odd = 4;
	bool is_odd_true = is_odd(good_odd);
	bool is_odd_false = is_odd(bad_odd);

	printf("Test 1: num = %d\n", good_odd);
	printf("Expected Output: %d\nActual Output %d\n", 0, good_odd);
	cout << "Test 1 Status: ";
	if (is_odd_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;
	
	printf("Test 2: num = %d\n", bad_odd);
	printf("Expected Output: %d\nActual Output %d\n", 1, bad_odd);
	cout << "Test 2 Status: ";
	if (!is_odd_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* equality_test *************************/
	cout << get_header("Testing equality_test") << endl;
	int equality_low = 1;
	int equality_high = 3;
	int equality_test_negative = equality_test(equality_low, equality_high);
	int equality_test_positive = equality_test(equality_high, equality_low);
	int equality_test_zero = equality_test(equality_low, equality_low);

	printf("Test 1: num1 = %d, num2 = %d\n", equality_low, equality_high);
	printf("Expected Output: %d\nActual Output %d\n", -1, equality_test_negative);
	cout << "Test 1 Status: ";
	if (equality_test_negative == -1)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: num1 = %d, num2 = %d\n", equality_high, equality_low);
	printf("Expected Output: %d\nActual Output %d\n", 1, equality_test_positive);
	cout << "Test 2 Status: ";
	if (equality_test_positive == 1)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 3: num1 = %d, num2 = %d\n", equality_low, equality_low);
	printf("Expected Output: %d\nActual Output %d\n", 0, equality_test_zero);
	cout << "Test 3 Status: ";
	if (equality_test_zero == 0)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* float_is_equal *************************/
	cout << get_header("Testing float_is_equal") << endl;
	float float_equal1 = 4;
	float float_equal2 = 4.0025;
	float precision_good = 0.01;
	float precision_bad = 0.0001;
	bool float_equal_true = float_is_equal(float_equal1, float_equal2, precision_good);
	bool float_equal_false = float_is_equal(float_equal1, float_equal2, precision_bad);

	printf("Test 1: num1 = %f, num2 = %f, precision = %f\n", float_equal1, float_equal2, precision_good);
	printf("Expected Output: %d\nActual Output %d\n", 0, float_equal_true);
	cout << "Test 1 Status: ";
	if (float_equal_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: num1 = %f, num2 = %f, precision = %f\n", float_equal1, float_equal2, precision_bad);
	printf("Expected Output: %d\nActual Output %d\n", 1, float_equal_false);
	cout << "Test 2 Status: ";
	if (!float_equal_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* numbers_present *************************/
	cout << get_header("Testing numbers_present") << endl;
	string with_numbers = "1234asdf";
	string without_numbers = "asdf";
	bool numbers_present_true = numbers_present(with_numbers);
	bool numbers_present_false = numbers_present(without_numbers);

	printf("Test 1: sentence = \"%s\"\n", with_numbers.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 0, numbers_present_true);
	cout << "Test 1 Status: ";
	if (numbers_present_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: sentence = \"%s\"\n", without_numbers.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, numbers_present_false);
	cout << "Test 2 Status: ";
	if (!numbers_present_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* letters_present *************************/
	cout << get_header("Testing letters_present") << endl;
	string with_letters = "1234asdf";
	string without_letters = "1234";
	bool letters_present_true = letters_present(with_letters);
	bool letters_present_false = letters_present(without_letters);

	printf("Test 1: sentence = \"%s\"\n", with_letters.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 0, letters_present_true);
	cout << "Test 1 Status: ";
	if (letters_present_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: sentence = \"%s\"\n", without_letters.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, letters_present_false);
	cout << "Test 2 Status: ";
	if (!letters_present_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* contains_sub_string *************************/
	cout << get_header("Testing contains_sub_string") << endl;
	string haystack = "The quick brown fox";
	string good_needle = "brown";
	string bad_needle = "moon";
	bool contains_sub_string_true = contains_sub_string(haystack, good_needle);
	bool contains_sub_string_false = contains_sub_string(haystack, bad_needle);

	printf("Test 1: sentence = \"%s\", sub_string = \"%s\"\n", haystack.c_str(), good_needle.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 0, contains_sub_string_true);
	cout << "Test 1 Status: ";
	if (contains_sub_string_true)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: sentence = \"%s\", sub_string = \"%s\"\n", haystack.c_str(), bad_needle.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, contains_sub_string_false);
	cout << "Test 2 Status: ";
	if (!contains_sub_string_false)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* word_count *************************/
	cout << get_header("Testing word_count") << endl;
	string words5 = "hello my  dear aunt sally";
	string words3 = "what the  heck";
	string word = "bonjour";
	int word_count5 = word_count(words5);
	int word_count3 = word_count(words3);
	int word_count1 = word_count(word);

	printf("Test 1: sentence = \"%s\"\n", words5.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 5, word_count5);
	cout << "Test 1 Status: ";
	if (word_count5 == 5)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 2: sentence = \"%s\"\n", words3.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 3, word_count3);
	cout << "Test 2 Status: ";
	if (word_count3 == 3)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	printf("Test 3: sentence = \"%s\"\n", word.c_str());
	printf("Expected Output: %d\nActual Output %d\n", 1, word_count1);
	cout << "Test 3 Status: ";
	if (word_count1 == 1)
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* to_upper *************************/
	cout << get_header("Testing to_upper") << endl;
	string upper_test = "hElLo WoRlD";
	string upper_expected_result = "HELLO WORLD";
	string upper_result = to_upper(upper_test);

	printf("Test 1: sentence = \"%s\"\n", upper_test.c_str());
	printf("Expected Output: %s\nActual Output %s\n", upper_expected_result.c_str(), upper_result.c_str());
	cout << "Test 1 Status: ";
	if (upper_result == "HELLO WORLD")
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* to_lower *************************/
	cout << get_header("Testing to_lower") << endl;
	string lower_test = "hElLo WoRlD";
	string lower_expected_result = "hello world";
	string lower_result = to_lower(lower_test);

	printf("Test 1: sentence = \"%s\"\n", lower_test.c_str());
	printf("Expected Output: %s\nActual Output %s\n", lower_expected_result.c_str(), lower_result.c_str());
	cout << "Test 1 Status: ";
	if (lower_result == "hello world")
		cout << pass << endl;
	else
		cout << fail << endl;
	cout << endl;

	/************************* get_int *************************/
	cout << get_header("Testing get_int") << endl;
	int get_int_res = get_int("Please enter an integer: ");
	printf("Your integer is: %d\n", get_int_res);
	cout << endl;

	/************************* get_float *************************/
	cout << get_header("Testing get_float") << endl;
	float get_float_res = get_float("Please enter a float: ");
	printf("Your float is: %f\n", get_float_res);
}
