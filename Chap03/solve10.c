#include <stdio.h>

#define SIZE 10

int delete(int arr[], int loc);
void print(int arr[]);

int main() {
	int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(arr);
	printf("====================\n");
	delete(arr, 1);
	print(arr);
}

int delete(int arr[], int loc) {
	int data = arr[loc];
	for (int i = loc; i < SIZE; i++) {
		arr[i] = arr[i + 1];
	}
	return data;
}

void print(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
