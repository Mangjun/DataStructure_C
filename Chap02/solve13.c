#include <stdio.h>
#include <time.h>

int sum(int n);

int main() {
	clock_t start, stop;
	double sec;
	
	start = clock();
	printf("sum : %d\n", sum(10000));
	stop = clock();

	sec = (stop - start) / CLOCKS_PER_SEC;
	printf("time : %f\n", sec);

	return 0;
}

int sum(int n) {
	if (n == 1) return 1;
	else return n + sum(n - 1);
}
