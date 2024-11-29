#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;

typedef struct Node {
	element data;
	struct Node *next;
} Node;

void error(char *message);
Node* insertFirst(Node *head, element value);
void printList(Node *head);

int main() {
	Node *head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insertFirst(head, data);
	printList(head);

	strcpy(data.name, "KIWI");
	head = insertFirst(head, data);
	printList(head);

	strcpy(data.name, "BANANA");
	head = insertFirst(head, data);
	printList(head);

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

void printList(Node *head) {
	Node *temp = head;

	while(temp->next != NULL) {
		printf("%s->", temp->data.name);
		temp = temp->next;
	}
	printf("%s\n", temp->data.name);
}
