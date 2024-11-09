#include <stdio.h>

int recursive(int n);

int main() {
	recursive(5);
	return 0;
}

int recursive(int n) {
	if (n != 1) recursive(n - 1);
	printf("%d\n", n);
}
