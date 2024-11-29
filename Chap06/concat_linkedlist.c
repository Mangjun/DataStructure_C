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
Node* concatList(Node *head1, Node *head2);

int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;

	head1 = insertFirst(head1, 10);
	head1 = insertFirst(head1, 20);
	head1 = insertFirst(head1, 30);
	printList(head1);

	head2 = insertFirst(head2, 40);
	head2 = insertFirst(head2, 50);
	printList(head2);

	Node *total = concatList(head1, head2);
	printList(total);

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

Node* concatList(Node *head1, Node *head2) {
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	} else {
		Node *temp = head1;
		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = head2;

		return head1;
	}
}
