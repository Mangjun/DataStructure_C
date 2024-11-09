#include <stdio.h>

void asterisk(int i);

int main() {
	asterisk(5);
	printf("\n");
	return 0;
}

void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
}
