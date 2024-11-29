#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertFirst(Node *head, element value);
void printList(Node *head);
Node* searchList(Node *head, element find);

int main() {
	Node *head = NULL;

	head = insertFirst(head, 10); printList(head);
	head = insertFirst(head, 20); printList(head);
	head = insertFirst(head, 30); printList(head);

	if (searchList(head, 30) != NULL) {
		printf("Find success!\n");
	} else {
		printf("Find fail..\n");
	}

	return 0;
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
	while (temp->next != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

Node* searchList(Node *head, element find) {
	Node *temp = head;
	while (temp != NULL) {
		if (temp->data == find) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}
