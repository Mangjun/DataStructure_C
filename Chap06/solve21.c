#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coef;
	int expon;
	struct Node *next;
} Node;

typedef struct List {
	int size;
	Node *head;
	Node *tail;
} List;

void error(char *message);
List* create();
void insertLast(List *list, int coef, int expon);
void polyAdd(List *list, List *list2, List *result);
void polyPrint(List* list);
int pow(int value, int expon); 
int polyEval(List *list, int value);

int main() {
	List *list1;

	list1 = create();

	insertLast(list1, 1, 3);
	insertLast(list1, 2, 1);
	insertLast(list1, 6, 0);

	polyPrint(list1);

	printf("value : %d -> %d\n", 2, polyEval(list1, 2));

	free(list1);

	return 0;
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

List* create() {
	List *list = (List *) malloc(sizeof(List));
	list->size = 0;
	list->head = list->tail = NULL;
	return list;
}

void insertLast(List *list, int coef, int expon) {
	Node *newNode = (Node *) malloc(sizeof(Node));

	newNode->coef = coef;
	newNode->expon = expon;
	newNode->next = NULL;

	if (list->tail == NULL) {
		list->head = list->tail = newNode;
	} else {
		list->tail->next = newNode;
		list->tail = newNode;
	}

	list->size++;
}

void polyAdd(List *list, List *list2, List *result) {
	Node* head1 = list->head;
	Node* head2 = list2->head;
	int sum;

	while (head1 && head2) {
		if (head1->expon == head2->expon) {
			sum = head1->coef + head2->coef;
			if (sum != 0) {
				insertLast(result, sum, head1->expon);
			}
			head1 = head1->next;
			head2 = head2->next;
		} else if (head1->expon > head2->expon) {
			insertLast(result, head1->coef, head1->expon);
			head1 = head1->next;
		} else {
			insertLast(result, head2->coef, head2->expon);
			head2 = head2->next;
		}
	}

	for (; head1 != NULL; head1 = head1->next) {
		insertLast(result, head1->coef, head1->expon);
	}

	for (; head2 != NULL; head2 = head2->next) {
		insertLast(result, head2->coef, head2->expon);
	}

}

void polyPrint(List* list) {
	Node *index = list->head;

	printf("polynomial = ");
	while (index->next != NULL) {
		printf("%d^%d + ", index->coef, index->expon);
		index = index->next;
	}
	printf("%d^%d\n", index->coef, index->expon);
}

int pow(int value, int expon) {
	int sum = value;
	for (int i = 0; i < expon - 1; i++) {
		sum *= value;
	}
	
	return sum;
}

int polyEval(List *list, int value) {
	Node *index = list->head;
	int sum = 0;

	while (index != NULL) {
		if (index->expon == 0) {
			sum += index->coef;
		} else if (index->expon > 0) {
			sum += (index->coef) * pow(value, index->expon);	
		} else {
			sum += (index->coef) / pow(value, index->expon);
		}
		index = index->next;
	}

	return sum;
}
