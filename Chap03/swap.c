#include <stdio.h>

void swap(int *px, int *py);

int main() {
	int a = 1, b = 2;
	printf("Swap Before | a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("Swap After | a : %d, b : %d\n", a, b);

	return 0;
}

void swap(int *px, int *py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
