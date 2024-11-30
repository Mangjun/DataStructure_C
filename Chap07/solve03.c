#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element data);
Node* insertFirst(Node *head, element data);
Node* search(Node *head, element data);
void printList(Node *head);

int main() {
	Node *head = NULL;
	Node *search_node;

	head = insertLast(head, 20); printList(head);
	head = insertLast(head, 30); printList(head);
	head = insertLast(head, 40); printList(head);
	head = insertFirst(head, 10); printList(head);

	if ((search_node = search(head, 50)) != NULL) {
		printf("Search %d  Success\n", 50);
	} else {
		printf("Search %d  Fail\n", 50);
	}

	return 0;
}

Node* insertLast(Node *head, element data) {
	Node *index = head;

	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = head;

	if (head == NULL) {
		new_node->next = new_node;
		head = new_node;
	} else {
		while (index->next != head) {
			index = index->next;
		}
		index->next = new_node;
	}

	return head;
}

Node* insertFirst(Node *head, element data) {
	Node *index = head;

	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = head;

	if (head == NULL) {
		new_node->next = new_node;
		head = new_node;
	} else {
		while (index->next != head) {
			index = index->next;
		}
		index->next = new_node;
		head = new_node;
	}

	return head;
}

Node* search(Node *head, element data) {
	Node *index = head;

	do {
		if (index->data == data) {
			return index;
		}
		index = index->next;
	}
	while (index != head);

	return NULL;
}

void printList(Node *head) {
	Node *index = head;

	do {
		printf("%d->", index->data);
		index = index->next;
	} while (index != head);

	printf("\n");
}
