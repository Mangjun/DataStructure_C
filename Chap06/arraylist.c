#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayList;

void error(char *message);
void init(ArrayList *list);
int isEmpty(ArrayList *list);
int isFull(ArrayList *list);
element getEntry(ArrayList *list, int pos);
void printList(ArrayList *list);
void insertLast(ArrayList *list, element item);
void insert(ArrayList *list, int pos, element item);
element delete(ArrayList *list, int pos);

int main() {
	ArrayList list;

	init(&list);
	insert(&list, 0, 10); printList(&list);
	insert(&list, 0, 20); printList(&list);
	insert(&list, 0, 30); printList(&list);
	insertLast(&list, 40); printList(&list);
	delete(&list, 0); printList(&list);

	return 0;	
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayList *list) {
	list->size = 0;
}

int isEmpty(ArrayList *list) {
	return (list->size == 0);
}

int isFull(ArrayList *list) {
	return (list->size == MAX_LIST_SIZE);
}

element getEntry(ArrayList *list, int pos) {
	if (pos < 0 || pos >= list->size) {
		error("pos is error");
	}
	return list->array[pos];
}

void printList(ArrayList *list) {
	for (int i = 0; i < list->size - 1; i++) {
		printf("%d->", list->array[i]);
	}
	printf("%d\n", list->array[(list->size - 1)]);
}

void insertLast(ArrayList *list, element item) {
	if (isFull(list)) {
		error("List is Full!");
	}
	list->array[(list->size)++] = item;
}

void insert(ArrayList *list, int pos, element item) {
	if (isFull(list)) {
		error("List is Full!");
	}

	if (pos < 0 || pos > list->size) {
		error("pos is error");
	}

	for (int i = list->size; i > pos; i--) {
		list->array[i] = list->array[i - 1];
	}

	list->array[pos] = item;
	list->size++;
}

element delete(ArrayList *list, int pos) {
	if (pos < 0 || pos >= list->size) {
		error("pos is error");
	}

	element item = list->array[pos];

	for (int i = pos + 1; i < list->size; i++) {
		list->array[i - 1] = list->array[i];	
	}
	list->size--;
}
