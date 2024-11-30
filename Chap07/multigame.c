#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertFirst(Node *head, element data);

int main() {
	Node *head = NULL;

	head = insertFirst(head, "KIM");
	head = insertFirst(head, "PARK");
	head = insertFirst(head, "CHOI");

	Node *index = head;
	for (int i = 0; i < 10; i++) {
		printf("Current Player#%d : %s\n", i + 1, index->data);
		index = index->next;
	}

	return 0;
}

Node* insertFirst(Node *head, element data) {
	Node *index = head;
	Node *new_node = (Node *) malloc(sizeof(Node));
	strcpy(new_node->data, data);
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
