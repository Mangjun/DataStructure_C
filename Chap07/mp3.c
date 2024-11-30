#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DNode {
	element data;
	struct DNode *llink;
	struct DNode *rlink;
} DNode;

DNode* insert(DNode *head, element data);
void printList(DNode *head, DNode *current);

int main() {
	char ch;
	DNode *head = NULL;
	DNode *current;
	
	head = insert(head, "Mamamia");
	head = insert(head, "Dancing Queen");
	head = insert(head, "Baby");
	head = insert(head, "Love yourself");
	head = insert(head, "Only one");
	head = insert(head, "Fernando");

	current = head->rlink;
	printList(head, current);

	do {
		printf("Input (<, >, q) : ");
		ch = getchar();

		if (ch == '<') {
			current = current->llink;
		} else if (ch == '>') {
			current = current->rlink;
		}
		printList(head, current);
		getchar();
	} while (ch != 'q');

	return 0;
}

DNode* insert(DNode *head, element data) {
	DNode *index = head;

	DNode *new_node = (DNode *) malloc(sizeof(DNode));
	strcpy(new_node->data, data);
	new_node->rlink = head;

	if (head == NULL) {
		new_node->llink = new_node;
		new_node->rlink = new_node;
		head = new_node;
	} else {
		index = head->llink;
		index->rlink = new_node;
		new_node->llink = index;
		head->llink = new_node;
	}

	return head;
}

void printList(DNode *head, DNode *current) {
	DNode *index = head;

	do {
		if (index == current) {
			printf("<-| #%s# |->", index->data);
		} else {
			printf("<-| %s |->", index->data);
		}
		index = index->rlink;
	} while (index != head);
	printf("\n");
}
