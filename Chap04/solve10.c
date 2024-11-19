#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int capacity;
	int top;
} Stack;

void initStack(Stack *s, int capacity) {
	s->capacity = capacity;
	s->data = (int *) malloc(capacity * sizeof(int));
	s->top = -1;
}

int isEmpty(Stack *s) {
	return (s->top == -1);
}

int isFull(Stack *s) {
	return (s->top == (s->capacity - 1)); 
}

void push(Stack *s, int item) {
	if (isFull(s)) {
		fprintf(stderr, "stack is full!\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

int pop(Stack *s) {
	if (isEmpty(s)) {
		fprintf(stderr, "stack is empty!\n");
		return -1;
	}
	else {
		return s->data[(s->top)--];
	}
}

int peek(Stack *s) {
	if (isEmpty(s)) {
		fprintf(stderr, "stack is empty!\n");
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

int main() {
	int len;
	Stack s;

	printf("arr size : ");
	scanf("%d", &len);

	initStack(&s, len);

	printf("input : ");
	for (int i = 0; i < len; i++) {
		int input;
		scanf("%d", &input);
		push(&s, input);
	}

	printf("reverse : ");
	for (int i = 0; i < len; i++) {
		printf("%d ", pop(&s));
	}

	printf("\n");

	return 0;
} /* main() */
