#include <stdio.h>

int sum(int n);

int main() {
	printf("sum : %d\n", sum(10));
	return 0;
}

int sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}
