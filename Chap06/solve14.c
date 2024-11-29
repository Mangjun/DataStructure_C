#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char name[20];
	int age;
	double heigh;
} element;

typedef struct Node {
	element data;
	struct Node* next;
} Node;

Node* insertLast(Node *head, element value);
void printList(Node *head);

int main() {
	Node *head = NULL;
	
	element value1, value2, value3, value4;
	
	strcpy(value1.name, "Kim");
	value1.age = 34;
	value1.heigh = 1.7;

	head = insertLast(head, value1);

	strcpy(value2.name, "Park");
	value2.age = 27;
	value2.heigh = 1.2;

	head = insertLast(head, value2);

	strcpy(value3.name, "Lee");
	value3.age = 48;
	value3.heigh = 1.4;

	head = insertLast(head, value3);

	strcpy(value4.name, "Choi");
	value4.age = 30;
	value4.heigh = 1.3;

	head = insertLast(head, value4);

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

void printList(Node *head) {
	Node *index = head;
	int count = 0;

	while (index != NULL) {
		printf("Node#%d | Name : %s, Age : %d, Heigh : %.2lf\n", ++count, index->data.name, index->data.age, index->data.heigh);
		index = index->next;
	}
}
