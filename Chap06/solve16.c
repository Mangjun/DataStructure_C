#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element value);
Node* deleteOdd(Node *head);
void printList(Node *head);

int main() {
	Node *head = NULL;

	head = insertLast(head, 10);
	head = insertLast(head, 20);
	head = insertLast(head, 30);
	head = insertLast(head, 40);
	head = insertLast(head, 50);
	head = insertLast(head, 60);
	head = insertLast(head, 70);

	printList(head);

	head = deleteOdd(head);

	printList(head);

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

Node* deleteOdd(Node *head) {
	int count = 0;
	Node *index = head;
	Node *temp = NULL;
	Node *removed;

	while (index != NULL) {
		++count;
		if (count & 1) {
			removed = index;
			if (index == head) {
				head = index->next;
			} else {
				temp->next = index->next;		
			}
			index = index->next;
			free(removed);
		} else {
			temp = index;
			index = index->next;
		}
	}

	return head;
}

void printList(Node *head) {
	Node *index = head;

	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}

	printf("%d\n", index->data);
}
