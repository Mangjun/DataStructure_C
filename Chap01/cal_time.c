#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, stop;
	double duration;
	int i;

	start = clock(); // start
	
	for (i = 0; i < 1000000; i++) {
		;
	}

	stop = clock(); // end
	duration = (double) (stop - start) / CLOCKS_PER_SEC;
	printf("time : %f\n", duration);
	return 0;
}
