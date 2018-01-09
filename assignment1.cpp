#include <cmath>
#include <iostream>

using namespace std;

void doCos(float x) {
	float res = cos(x);
	
	cout << "Finding the cosine of " << x << endl;
	cout << "Result: " << res << endl;
}

void doSin(float x) {
	float sinRes = sin(x);
	float res = 2 * sinRes;
	
	cout << "Finding 2 times the sine of " << x << endl;
	cout << "sin(" << x << ") = " << sinRes << endl;
	cout << "Result: " << res << endl;
}

void doTan(float x) {
	float res = tan(x);
	
	cout << "Finding the tangent of " << x << endl;
	cout << "Result: " << res << endl;
}

void doLog(float base, float arg) {
	float lnBase = log(base);
	float lnArg = log(arg);
	float res = lnArg / lnBase;

	cout << "Finding the log base " << base << " of " << arg << endl;
	cout << "Natural log of " << base << ": " << lnBase << endl;
	cout << "Natural log of " << arg << ": " << lnArg << endl;
	cout << "Result ( ln(" << arg << ") / ln(" << base << ") ): " << res << endl;
}

void doNaturalLog(float arg) {
	float res = log(arg);

	cout << "Finding the natural log of " << arg << endl;
	cout << "Result: " << res << endl;
}

void doSinExponent(float x) {
	float sinRes = sin(x);
	float res = pow(3, sinRes);

	cout << "Finding 3 to the power of sine of " << x << endl;
	cout << "sin(" << x << ") = " << sinRes << endl;
	cout << "Result: " << res << endl;
}

void doPolyLog(float x) {
	float arg = pow(x, 2) + 1;
	
	cout << "Finding the log base 2 of " << x << "**2 + 1" << endl;
	cout << "Argument: " << arg << endl;
	
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
}