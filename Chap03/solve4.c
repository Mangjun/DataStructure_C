#include <stdio.h>

#define SIZE 10

int power(int x, int n);
void print(int list[]);

int main() {
	int two[SIZE];

/*
	for (int i = 0; i < SIZE; i++) {
		two[i] = power(2, i);
	}
*/

	two[0] = 1;
	for (int i = 1; i < SIZE; i++) {
		two[i] = two[i - 1] * 2;
	}

	print(two);

	return 0;
}

int power(int x, int n) {
	if (n == 0) return 1;
	else if (n & 1) {
		return x * power(x * x, (n - 1) / 2);
	} else {
		return power(x * x, n / 2);
	}

}

void print(int list[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}
