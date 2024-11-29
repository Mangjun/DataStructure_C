#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
} Node;

Node* add(Node *head, element item);
Node* delete(Node *head, element item);
Node* clear(Node *head);
int isInList(Node *head, element item);
int getLength(Node *head);
int isEmpty(Node *head);
void display(Node *head);

int main() {
	Node *head = NULL;

	head = add(head, 1); display(head);
	head = add(head, 2); display(head);
	head = add(head, 4); display(head);
 	head = add(head, 3); display(head);
	head = add(head, 5); display(head);
	head = add(head, 10); display(head);
	head = add(head, 7); display(head);
	head = add(head, 6); display(head);
	head = add(head, 9); display(head);
	head = add(head, 8); display(head);

	return 0;
}

Node* add(Node *head, element item) {
	Node *index = head;
	Node *temp;
	
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = item;

	if (head == NULL) {
		head = new_node;
		return head;
	} else {
		while (index != NULL) {
			if (index->data > item) {
				temp->next = new_node;
				new_node->next = index;
				return head;
			}
			temp = index;
			index = index->next;
		}
		temp->next = new_node;
	}

	return head;
}

Node* delete(Node *head, element item) {
	Node *index = head;
	Node *temp, *removed;

	while (index != NULL) {
		if (index->data == item) {
			removed = index;
			temp->next = index->next;
			index = index->next;
			free(removed);
		} else {
			temp = index;
			index = index->next;
		}
	}	

	return head;
}

Node* clear(Node *head) {
	Node *index = head;
	Node *temp;
	while (index != NULL) {
		temp = index;
		index = index->next;
		free(temp);
	}

	head = NULL;
	return head;
}

int isInList(Node *head, element item) {
	Node *index = head;
	
	while (index != NULL) {
		if (index->data == item) {
			return 1;
		}
		index = index->next;
	}

	return 0;
}

int getLength(Node *head) {
	Node *index = head;
	int count = 0;

	while (index != NULL) {
		count++;
		index = index->next;
	}

	return count;
}

int isEmpty(Node *head) {
	return head == NULL;
}

void display(Node *head) {
	Node *index = head;

	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}
	printf("%d\n", index->data);
}
