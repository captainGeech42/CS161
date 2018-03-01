#include <stdio.h>

using namespace std;

void insert_values(int length, int** array) {
	*array = new int[length];
	for (int i = 0; i < length; i++) {
		(*array)[i] = 5;
	}
}

int main() {
	int length = 6;
	int* my_arr;
	insert_values(length, &my_arr);

	printf("%d\n", my_arr[length-1]);

	return 0;
}
