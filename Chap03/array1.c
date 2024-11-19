#include <stdio.h>

#define SIZE 6

void get_integers(int list[]);
int cal_sum(int list[]);

int main() {
	int list[SIZE];
	get_integers(list);
	printf("sum : %d\n", cal_sum(list));
	return 0;
}

void get_integers(int list[]) {
	printf("Input 6 integers : ");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += list[i];
	}
	return sum;
}
