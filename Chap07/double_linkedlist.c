#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DNode {
	element data;
	struct DNode *llink;
	struct DNode *rlink;
} DNode;

DNode* insert(DNode *head, element data);
void printList(DNode *head);

int main() {
	DNode *head = NULL;

	head = insert(head, 10); printList(head);
	head = insert(head, 20); printList(head);
	head = insert(head, 30); printList(head);
	head = insert(head, 40); printList(head);

	return 0;
}

DNode* insert(DNode *head, element data) {
	DNode *index = head;

	DNode *new_node = (DNode *) malloc(sizeof(DNode));
	new_node->data = data;
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

void printList(DNode *head) {
	DNode *index = head;

	do {
		printf("<-%d->", index->data);
		index = index->rlink;
	} while (index != head);
	printf("\n");
}
