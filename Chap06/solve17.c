#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* insertNodeLast(Node *head, Node *node);
Node* insertLast(Node *head, element value);
Node* alternate(Node *list1, Node *list2, Node *new_list);
void printList(Node *head);

int main() {
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *new_list = NULL;

	head1 = insertLast(head1, 10);
	head2 = insertLast(head2, 20);
	head1 = insertLast(head1, 30);
	head2 = insertLast(head2, 40);
	head1 = insertLast(head1, 50);
	head2 = insertLast(head2, 60);
	head1 = insertLast(head1, 70);

	printList(head1); printList(head2);

	new_list = alternate(head1, head2, new_list);

	printList(new_list);

	return 0;
}

Node* insertNodeLast(Node *head, Node *node) {
	Node *index = head;
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = node->data;

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

Node* insertLast(Node *head, element value) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = value;

	head = insertNodeLast(head, new_node);

	return head;
}

Node* alternate(Node *list1, Node *list2, Node *new_list) {
	Node *head1 = list1;
	Node *head2 = list2;

	if (head1 == NULL) {
		return list2;
	}

	if (head2 == NULL) {
		return list1;
	}

	while (head1 && head2) {
		new_list = insertNodeLast(new_list, head1);
		head1 = head1->next;
		new_list = insertNodeLast(new_list, head2);
		head2 = head2->next;
	}

	for (; head1 != NULL; head1 = head1->next) {
		new_list = insertNodeLast(new_list, head1);
	}

	for (; head2 != NULL; head2 = head2->next) {
		new_list = insertNodeLast(new_list, head2);
	}

	return new_list;
}

void printList(Node *head) {
	Node *index = head;
	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}
	printf("%d\n", index->data);
}
