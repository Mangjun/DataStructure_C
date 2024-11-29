#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element value);
Node* split(Node *list, Node **odd_list, Node **even_list);
void printList(Node *head);

int main() {
	Node *head = NULL;
	Node *odd_list = NULL;
	Node *even_list = NULL;

	head = insertLast(head, 10);
	head = insertLast(head, 20);
	head = insertLast(head, 30);
	head = insertLast(head, 40);
	head = insertLast(head, 50);

	printList(head);

	head = split(head, &odd_list, &even_list);

	printList(odd_list);
	printList(even_list);

	return 0;
}

Node* insertLast(Node *head, element value) {
	Node *index = head;
	
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = value;

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

Node* split(Node *list, Node **odd_list, Node **even_list) {
	Node *index = list;
	int count = 0;

	while (index != NULL) {
		count++;
		if (count & 1) {
			*odd_list = insertLast(*odd_list, index->data);
		} else {
			*even_list = insertLast(*even_list, index->data);
		}
		index = index->next;
	}

	return list;
}

void printList(Node *head) {
	Node *index = head;
	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}
	printf("%d\n", index->data);
}
