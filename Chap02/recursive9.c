#include <stdio.h>

int recursive(int n);

int main() {
	printf("recur : %d\n", recursive(10));
	return 0;
}

int recursive(int n) {
	printf("%d\n", n);
	if (n < 1) return -1;
	else return recursive(n - 3) + 1;
}
