/*********************************************************************
** Program Filename: assignment1.cpp
** Author: Alexander Nead-Work
** Date: 01/08/2018
** Description: Solution file for CS161 Assignment 1
** Input: None
** Output: Various math operation results
*********************************************************************/

#include <cmath>
#include <iostream>
#include <stdio.h>


using namespace std;


/*********************************************************************
** Function: doCos
** Description: Executes the cosine operation in assignment description
** Parameters: x=input float value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doCos(float x) {
	float res = cos(x);
	
	printf("Finding the cosine of %f\n", x);
	printf("Result: %f\n", res);
}


/*********************************************************************
** Function: doSin
** Description: Executes the sine operation in assignment description
** Parameters: x=input float value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doSin(float x) {
	float sinRes = sin(x);
	float res = 2 * sinRes;
	
	printf("Finding 2 times the sine of %f\n", x);
	printf("sin(%f) = %f\n", x, sinRes);
	printf("Result: %f\n", res);
}


/*********************************************************************
** Function: doTan
** Description: Executes the tangent operation in assignment description
** Parameters: x=input float value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doTan(float x) {
	float res = tan(x);
	
	printf("Finding the tangent of %f\n", x);
	printf("Result: %f\n", res);
}


/*********************************************************************
** Function: doLog
** Description: Executes the logarithm operation in assignment description
** Parameters: base=float base value, arg=float argument value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doLog(float base, float arg) {
	float lnBase = log(base);
	float lnArg = log(arg);
	float res = lnArg / lnBase;
	
	printf("Finding the log base %f of %f\n", base, arg);
	printf("Natural log of %f: %f\n", base, lnBase);
	printf("Natural log of %f: %f\n", arg, lnArg);
	printf("Result ( ln(%f) / ln(%f) ): %f\n", arg, base, res);
}


/*********************************************************************
** Function: doNaturalLog
** Description: Executes the natural log operation in assignment description
** Parameters: arg=float argument value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doNaturalLog(float arg) {
	float res = log(arg);

	printf("Finding the natural log of %f\n", arg);
	printf("Result: %f\n", res);
}


/*********************************************************************
** Function: doSinExponent
** Description: Executes the exponential sine operation in assignment description
** Parameters: x=input float value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doSinExponent(float x) {
	float sinRes = sin(x);
	float res = pow(3, sinRes);
	
	printf("Finding 3 to the power of the sine of %f\n", x);
	printf("sin(%f) = %f\n", x, sinRes);
	printf("Result: %f\n", res);
}


/*********************************************************************
** Function: doPolyLog
** Description: Executes the logarithm of a polynomial operation in assignment description
** Parameters: x=input float value
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void doPolyLog(float x) {
	float arg = pow(x, 2) + 1;
	
	printf("Finding the log base 2 of %f**2 + 1\n", x);
	printf("Argument: %f\n", arg);
	
	doLog((float)2, arg);
}


/*********************************************************************
** Function: printNewline
** Description: Prints a newline to the screen
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
void printNewline() {
	cout << endl;
}


/*********************************************************************
** Function: main
** Description: Executes the cosine operation in assignment description
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Text to screen
*********************************************************************/ 
int main() {
	doCos((float)2/3);
	printNewline();

	doSin((float)2/3);
	printNewline();

	doTan(-0.75);
	printNewline();

	doLog((float)10, (float)55);
	printNewline();

	doLog((float)2, (float)15);
	printNewline();

	doLog((float)4, (float)40);
	printNewline();

	for (int i = 1; i <= 3; i++) {
		float x = 1 * pow(10, i) / 10;

		doSinExponent(x);
		printNewline();

		doPolyLog(x);
		printNewline();
	}

	return 0;
}
