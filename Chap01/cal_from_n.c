#include <stdio.h>
#include <time.h>

int cal_from_n_for(int n);
int cal_from_n_math(int n);

int main() {
	printf("sum : %d\n", cal_from_n_for(100000));
	printf("sum : %d\n", cal_from_n_math(100000));

	return 0;
}

int cal_from_n_for(int n) {
	clock_t start, stop;
	double duration;
	int i;
	int sum = 0;

	start = clock();

	for (i = 1; i <= n; i++) {
		sum += i;
	}

	stop = clock();
	duration = (double) (stop - start) / CLOCKS_PER_SEC;
	printf("for time : %f\n", duration);

	return sum;
}

int cal_from_n_math(int n) {
	time_t start, stop;
	double duration;
	int sum;

	start = clock();

	sum = n * (n + 1) / 2;

	stop = clock();
	duration = (double) (stop - start) / CLOCKS_PER_SEC;
	printf("math time : %f\n", duration);

	return sum;
}
