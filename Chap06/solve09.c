#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element value);
void printList(Node *head);

int main() {
	int count;
	int value;
	Node *head = NULL;

	printf("Count of Node : ");
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		printf("Node#%d : ", i + 1);
		scanf("%d", &value);
		head = insertLast(head, value);
	}

	printList(head);

	return 0;
}

Node* insertLast(Node *head, element value) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	
	Node *temp = head;

	if (head == NULL) {
		head = newNode;
	} else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
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
