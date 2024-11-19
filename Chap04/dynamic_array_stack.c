#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
} StackType;

void initStack(StackType *s);
int isEmpty(StackType *s);
int isFull(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);

int main() {
	StackType s;

	initStack(&s);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	free(s.data);
	return 0;
}

void initStack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element *) malloc(s->capacity * sizeof(element));
}

int isEmpty(StackType *s) {
	return (s->top == -1);
}

int isFull(StackType *s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType *s, element item) {
	if (isFull(s)) {
		s->capacity *= 2;
		s->data = (element *) realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType *s) {
	if (isEmpty(s)) {
		fprintf(stderr, "stack is empty!\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(StackType *s) {
	if (isEmpty(s)) {
		fprintf(stderr, "stack is empty!\n");
		exit(1);
	}
	else {
		return s->data[(s->top)];
	}
}
