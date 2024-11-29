#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

void error(char *message);
Node* insertFirst(Node *head, element value);
Node* insert(Node *head, Node *pre, element value);
Node* deleteFirst(Node *head);
Node* delete(Node *head, Node *pre);
void printList(Node *head);

int main() {
	Node *head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insertFirst(head, i);
		printList(head);
	}

	for (int i = 0; i < 5; i++) {
		head = deleteFirst(head);
		printList(head);
	}

	return 0;
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

Node* insertFirst(Node *head, element value) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = head;
	head = newNode;

	return head;
}

Node* insert(Node *head, Node *pre, element value) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = pre->next;
	pre->next = newNode;

	return head;
}

Node* deleteFirst(Node *head) {
	if (head == NULL) {
		return NULL;
	}

	Node *temp = head;
	head = temp->next;
	free(temp);
	
	return head;
}

Node* delete(Node *head, Node *pre) {
	Node *temp = pre->next;
	pre->next = temp->next;
	free(temp);

	return head;
}

void printList(Node *head) {
	Node *temp = head;
	while (temp->next != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}
