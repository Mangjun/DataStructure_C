#include <stdio.h>

#define SIZE 10

void insert(int arr[], int loc, int value);
void print(int arr[]);

int main() {
	int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(arr);
	printf("====================\n");
	insert(arr, 1, 10);
	print(arr);
}

void insert(int arr[], int loc, int value) {
	for (int i = SIZE - 1; i > loc; i--) {
		arr[i] = arr[i - 1];
	}
	arr[loc] = value;
}

void print(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
