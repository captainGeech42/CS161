#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

void doCos(float x) {
	float res = cos(x);
	
	printf("Finding the cosine of %f\n", x);
	printf("Result: %f\n", res);
}

void doSin(float x) {
	float sinRes = sin(x);
	float res = 2 * sinRes;
	
	printf("Finding 2 times the sine of %f\n", x);
	printf("sin(%f) = %f\n", x, sinRes);
	printf("Result: %f\n", res);
}

void doTan(float x) {
	float res = tan(x);
	
	printf("Finding the tangent of %f\n", x);
	printf("Result: %f\n", res);
}

void doLog(float base, float arg) {
	float lnBase = log(base);
	float lnArg = log(arg);
	float res = lnArg / lnBase;
	
	printf("Finding the log base %f of %f\n", base, arg);
	printf("Natural log of %f: %f\n", base, lnBase);
	printf("Natural log of %f: %f\n", arg, lnArg);
	printf("Result ( ln(%f) / ln(%f) ): %f\n", arg, base, res);
}

void doNaturalLog(float arg) {
	float res = log(arg);

	printf("Finding the natural log of %f\n", arg);
	printf("Result: %f\n", res);
}

void doSinExponent(float x) {
	float sinRes = sin(x);
	float res = pow(3, sinRes);
	
	printf("Finding 3 to the power of the sine of %f\n", x);
	printf("sin(%f) = %f\n", x, sinRes);
	printf("Result: %f\n", res);
}

void doPolyLog(float x) {
	float arg = pow(x, 2) + 1;
	
	printf("Finding the log base 2 of %f**2 + 1\n", x);
	printf("Argument: %f\n", arg);
	
	doLog((float)2, arg);
}

void printNewline() {
	cout << endl;
}

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
