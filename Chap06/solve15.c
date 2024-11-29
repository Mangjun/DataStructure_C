#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element value);
element max(Node *head);
element min(Node *head);
void printList(Node *head);

int main() {
	Node *head = NULL;

	head = insertLast(head, 10);
	head = insertLast(head, 20);
	head = insertLast(head, 30);
	head = insertLast(head, 40);

	printf("max : %d\n", max(head));
	printf("min : %d\n", min(head));

	return 0;
}

Node* insertLast(Node *head, element value) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = value;

	Node *index = head;

	if (head == NULL) {
		head = new_node;
	} else {
		while (index->next != NULL) {
			index = index->next;
		}
		index->next = new_node;
	}

	return head;
}

element max(Node *head) {
	element max = head->data;
	Node *index = head;

	while (index != NULL) {
		if (index->data > max) {
			max = index->data;
		}
		index = index->next;
	}

	return max;
}

element min(Node *head) {
	element min = head->data;
	Node *index = head;

	while (index != NULL) {
		if (index->data < min) {
			min = index->data;
		}
		index = index->next;
	}

	return min;
}

void printList(Node *head) {
	Node *index = head;

	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}
	printf("%d\n", index->data);
}
