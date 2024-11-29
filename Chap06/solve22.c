#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct ArrayList {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayList;

void error(char *message);

void initArrayList(ArrayList *list);
void add(ArrayList *list, element item);
void delete(ArrayList *list, element item);
void clear(ArrayList *list);
int isInList(ArrayList *list, element item);
int getLength(ArrayList *list);
int isEmpty(ArrayList *list);
int isFull(ArrayList *list);
void display(ArrayList *list);

int main() {
	ArrayList list;

	initArrayList(&list);

	add(&list, 1); display(&list);
	add(&list, 10); display(&list);
	add(&list, 2); display(&list);
	add(&list, 9); display(&list);
	add(&list, 3); display(&list);
	add(&list, 8); display(&list);
	add(&list, 4); display(&list);
	add(&list, 7); display(&list);
	add(&list, 5); display(&list);
	add(&list, 6); display(&list);

	return 0;
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initArrayList(ArrayList *list) {
	list->size = 0;
}

void add(ArrayList *list, element item) {
	if (isFull(list)) {
		error("List is full!\n");
	}
	
	int i;
	for (i = 0; i < list->size; i++) {
		if (list->array[i] > item) {
			break;
		}
	}

	for (int ii = (list->size - 1); ii >= i; ii--) {
		list->array[ii + 1] = list->array[ii];
	}

	list->array[i] = item;
	list->size++;
}

void delete(ArrayList *list, element item) {
	if (isEmpty(list)) {
		error("List is empty");
	}

	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == item) {
			for (int ii = i; ii < list->size - 1; ii++) {
				list->array[ii] = list->array[ii + 1];
			}
			list->size--;
		}
	}
}

void clear(ArrayList *list) {
	list->size = 0;
}

int isInList(ArrayList *list, element item) {
	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == item) {
			return 1;
		}
	}
	return 0;
}

int getLength(ArrayList *list) {
	return list->size;
}

int isEmpty(ArrayList *list) {
	return (list->size == 0);
}

int isFull(ArrayList *list) {
	return (list->size == MAX_LIST_SIZE);
}

void display(ArrayList *list) {
	for (int i = 0; i < list->size - 1; i++) {
		printf("%d->", list->array[i]);
	}
	printf("%d\n", list->array[list->size - 1]);
}
