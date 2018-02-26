/*********************************************************************
** Program Filename: assignment4.cpp
** Author: Alexander Nead-Work
** Date: 02/17/2018
** Description: Driver file for A4
** Input: n/a
** Output: n/a
*********************************************************************/

#include "assignment4.hpp"

using namespace std;

/*********************************************************************
** Function: main
** Description: Runs the program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main() {
    cout << "Welcome to only calculator you'll ever need in your life." << endl;

    cout << "Possible modes are:" << endl;
    cout << "(1) Standard Calculator" << endl;
    cout << "(2) Binary to Decimal" << endl;
    cout << "(3) Decimal to Binary" << endl;
    cout << "(4) Grade Calculator" << endl;
    cout << "(5) Exit" << endl;

    int mode;

    do {
        mode = get_mode();

        switch (mode) {
            case 1:
                standard_calculator();
                break;
            case 2:
                binary_to_decimal();
                break;
            case 3:
                decimal_to_binary();
                break;
            case 4:
                grade_calculator();
                break;
            case 5:
                return 0;
        }
    } while (true);

    return 0;
}