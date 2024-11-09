#include <stdio.h>
#include <time.h>

int get_bin_coe_iter(int n, int k);
int get_bin_coe_cir(int n, int k);

int main() {
	clock_t start, stop;
	double time;

	printf("iter : %d\n", get_bin_coe_iter(10, 4));

	start = clock();
	printf("cir : %d\n", get_bin_coe_cir(10, 4));
	stop = clock();
	time = (stop - start) / CLOCKS_PER_SEC;
	printf("cir time : %f\n", time);

	return 0;
}

int get_bin_coe_iter(int n, int k) {
	clock_t start, stop;
	double time;

	stop = clock();

	if (k == 0 || k == n) {
		return 1;
	}

	int x = 1;
	int y = 1;

	for (int i = n; i > (n - k); i--) {
		x *= i;
	}

	for (int i = k; i != 1; i--) {
		y *= i;
	}

	stop = clock();
	time = (stop - start) / CLOCKS_PER_SEC;
	printf("iter time : %f\n", time);

	return x / y;
}

int get_bin_coe_cir(int n, int k) {
	if (k == 0 || k == n) return 1;
	else return get_bin_coe_cir(n - 1, k - 1) + get_bin_coe_cir(n - 1, k);
}
