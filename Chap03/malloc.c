#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main() {
	int *p;

	p = (int *) malloc(SIZE * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "Out of Memory\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++) {
		p[i] = i;
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	
	free(p);
	return 0;
}
