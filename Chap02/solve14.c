#include <stdio.h>
#include <time.h>

double sum(int n);

int main() {
	printf("sum : %f\n", sum(10));
}

double sum(int n) {
	if (n == 1) return 1.0;
	else return 1.0 / n + sum(n - 1);
}
