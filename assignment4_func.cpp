/*********************************************************************
** Program Filename: assignment4_func.cpp
** Author: Alexander Nead-Work
** Date: 02/17/2018
** Description: Function implementations for A4
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment4.hpp"

using namespace std;

void standard_calculator() {
    // get input
    string input = get_standard_calculator_input();

    // do some maths
    float total = 0;
    float operand_1 = 0;
    float operand_2 = 0;
    string operand_1_str;
    string operand_2_str;
    char current;
    char operation;
    unsigned short current_type = NUMBER;
    bool current_operand = OP1;

    for (int i = 0; i < input.length(); i++) {
        current = input[i];

        /*
         * progression is as follows:
         *  - number:op1 to operator
         *  - operator to number:op2
         *  - number:op2 to do_math
         *  - do_math to operator
         *  - operator to number:op2
         *  - and so on...
         */
        
        if (current_type == NUMBER) {
            if (current_operand == OP1) {
                if (current != ' ') {
                    operand_1_str.append(1, current);
                } else {
                    current_type = OPERATOR;
                    operand_1 = string_to_float(operand_1_str);
                    operand_1_str = "";
                }
            } else if (current_operand == OP2) {
                if (current != ' ') {
                    operand_2_str.append(1, current);
                }
                if (current == ' ' || i == input.length() - 1) {
                    current_type = DO_MATH;
                    operand_2 = string_to_float(operand_2_str);
                    operand_2_str = "";
                }
            } else {
                printf("Well that wasn't supposed to happen.\n");
            }
        } else if (current_type == OPERATOR) {
            operation = current;
            current_type = NUMBER;
            current_operand = OP2;
            i++;
        }
        if (current_type == DO_MATH || i == input.length() - 1) {
            float val;
            switch (operation) {
                case '+':
                    val = operand_1 + operand_2;
                    break;
                case '-':
                    val = operand_1 - operand_2;
                    break;
                case '*':
                    val = operand_1 * operand_2;
                    break;
                case '/':
                    val = operand_1 / operand_2;
                    break;
                default:
                    printf("Well that isn't possible.\n");
            }
            total = val;
            operand_1 = total;
            current_operand = OP2;
            current_type = OPERATOR;
        }
    }

    printf("The answer is %f\n", total);
}

string get_standard_calculator_input() {
    bool input_is_valid = true;
    string input;
    unsigned short current_type = NUMBER;
    unsigned short next_type = SPACE;
    unsigned short decimal_counter = 0;
    unsigned int operator_counter = 0;
    char current;

    do {
        if (!input_is_valid) {
            cout << "The expression entered was not valid." << endl;
            input_is_valid = true;
            current_type = NUMBER;
            next_type = SPACE;
            decimal_counter = 0;
            operator_counter = 0;
        }

        cout << "Enter an expression (format: [num] [oper] [num] ... [num] [oper] [num]; floats are valid): ";
        getline(cin, input);

        /*
         * number = 0
         * operator = 1
         * space = 2
         *
         * progression is as follows:
         *  - num to space
         *  - space to operator
         *  - operator to space
         *  - space to num
         *  - and so forth...
         */
        
        for (int i = 0; i < input.length(); i++) {
            current = input[i];

            if (current_type == NUMBER && ((current >= '0' && current <= '9') || (current == '.' && decimal_counter == 0))) {
                if (current == '.') {
                    decimal_counter++;
                }
            } else if (current_type == NUMBER) {
                // our character is not a valid part of a number
                if (current == ' ') {
                    // our character is a space, transition from num to space
                    current_type = SPACE;
                    next_type = OPERATOR;
                    decimal_counter = 0;
                } else {
                    input_is_valid = false;
                    break;
                }
            } else if (current_type == SPACE && next_type == OPERATOR) {
                if (current == '+' || current == '-' || current == '*' || current == '/') {
                    // our character is an operator, transition from space to operator
                    current_type = OPERATOR;
                    next_type = SPACE;
                    operator_counter++;
                } else {
                    input_is_valid = false;
                    break;
                }
            } else if (current_type == OPERATOR) {
                if (current == ' ') {
                    // our character is a space, transition from operator to space
                    current_type = SPACE;
                    next_type = NUMBER;
                } else {
                    input_is_valid = false;
                    break;
                }
            } else if (current_type == SPACE && next_type == NUMBER) {
                if ((current >= '0' && current <= '9') || current == '-') {
                    // our character is a valid start to a number, transition from space to number
                    current_type = NUMBER;
                    next_type = SPACE;
                } else {
                    input_is_valid = false;
                    break;
                }
            } else if (i == 0 && !((i >= '0' && i <= '9') || i == '-')) {
                // we have an invalid character at the beginning of the expression
                input_is_valid = false;
                break;
            } else if (i == input.length() - 1 && !(i >= '0' && i <= '9')) {
                // we have an invalid character at the end of the expression
                input_is_valid = false;
                break;
            } else {
                input_is_valid = false;
                break;
            }
        }

        if (operator_counter == 0) {
            input_is_valid = false;
        }
    } while (!input_is_valid);

    return input;
}

float string_to_float(string in) {
    int decimal_position = in.length();
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

int string_to_int(string in) {
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

void decimal_to_binary() {
    int decimal = get_decimal_binary_input();
    string result;

    while (decimal > 0) {
        result.append(1, (char)(decimal % 2) + 48);
        decimal /= 2;
    }

    cout << "The binary version is ";
    for (int i = result.length() - 1; i >= 0; i--)  {
        cout << result[i];
    }
    cout << endl;
}

int get_decimal_binary_input() {
    bool input_is_valid = true;
    string input;

    do {
        if (!input_is_valid) {
            cout << "The given input was not valid." << endl;
            input_is_valid = true;
        }

        cout << "Enter an unsigned integer: ";
        getline(cin, input);

        input_is_valid = is_unsigned_int(input);
    } while (!input_is_valid);

    return string_to_int(input);
}

/*********************************************************************
** Function: is_unsigned_int
** Description: Checks if a given string is a valid unsigned integer
** Parameters: string num
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool is_unsigned_int(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (!(num[i] >= '0' && num[i] <= '9' )) {
            return false;
        }
    }
    return true;
}

void binary_to_decimal() {
    string binary = get_binary_decimal_input();
    int result = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1')
            result += pow(2, binary.length() - i - 1);
    }

    printf("The decimal version is %d\n", result);
}

string get_binary_decimal_input() {
    bool input_is_valid = true;
    string input;

    do {
        if (!input_is_valid) {
            input_is_valid = true;
            cout << "The input given is not a valid binary number." << endl;
        }

        cout << "Please enter a binary number: ";
        getline(cin, input);

        input_is_valid = is_binary(input);
    } while (!input_is_valid);

    return input;
}

bool is_binary(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!(input[i] == '0' || input[i] == '1'))
            return false;
    }
    return true;
}

void grade_calculator() {
    string input;
    cout << "Please select (1) weighted or (2) unweighted: ";
    getline(cin, input);

    switch (input[0]) {
        case '1':
            printf("Your weighted average is %f\n", weighted_average());
            break;
        case '2':
            printf("Your unweighted average is %f\n", unweighted_average());
            break;
        default:
            cout << "Invalid choice received." << endl;
            return grade_calculator();
    }
}

float weighted_average() {
    float total_average = 0;
    int total_weight = 0;
    int sum_grades;

    int num_categories = get_int("Please enter the number of weighted categories: ");

    for (int i = 1; i <= num_categories; i++) {
        sum_grades = 0;

        cout << "Please enter the number of grades for category " << i << ": ";
        string idgaf;
        getline(cin, idgaf);

        string prompt = append_int_to_string("Please enter the grades for category ", i) + ":";
        string grades = get_grades(prompt);

        
    }
}

float unweighted_average() {

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

string get_grades(string prompt) {
    bool input_is_valid = true;
    string input;

    do {
        if (!input_is_valid) {
            input_is_valid = true;
            cout << "Invalid input received." << endl;
        }

        cout << prompt;
        getline(cin, input);

        input_is_valid = are_valid_grades(input);
    } while (!input_is_valid);

    return input;
}

bool are_valid_grades(string grades) {
    string temp;
    char current;
    for (int i = 0; i < grades.length(); i++) {
        current = grades[i];

        if (current >= '0' && current <= '9') {
            temp.append(1, current);
        } else if (current == ' ' || i == grades.length() - 1) {
            if (!is_valid_grade(temp))
                return false;
            temp = "";
        }
    }
    return true;
}

bool is_valid_grade(string grade) {
    //must be between 0 and 100
    int num = string_to_int(grade);
    return num >= 0 && num <= 100;
}

string append_int_to_string(string str, int num) {
    stringstream ss;
    ss << str;
    ss << num;
    return ss.str();
}