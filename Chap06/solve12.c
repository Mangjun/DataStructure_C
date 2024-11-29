#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertLast(Node *head, element value);
void printList(Node *head);
int countNode(Node *head);
int sumNodeData(Node *head);
int searchNodeCount(Node *head, element value);

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
	printf("Num of Node : %d\n", countNode(head));
	printf("Sum of Node data : %d\n", sumNodeData(head));
	printf("Num of %d in List : %d\n", 5, searchNodeCount(head, 5));

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

int countNode(Node *head) {
	int count = 0;
	Node *index = head;

	while(index != NULL) {
		count++;
		index = index->next;
	}

	return count;
}

int sumNodeData(Node *head) {
	int sum = 0;
	Node *index = head;

	while (index != NULL) {
		sum += index->data;
		index = index->next;
	}

	return sum;
}

int searchNodeCount(Node *head, element value) {
	int count = 0;
	Node *index = head;

	while (index != NULL) {
		if (index->data == value) {
			count++;
		}
		index = index->next;
	}

	return count;
}
