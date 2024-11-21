#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

typedef struct {
	Stack s1;
	Stack s2;
} Queue;

void error(char *message);

/* Stack */
void initStack(Stack *s);
int isFullStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, element item);
element pop(Stack *s);

/* Queue */
void initQueue(Queue *q);
int isFullQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, element item);
element dequeue(Queue *q);

int main() {
	Queue queue;

	initQueue(&queue);

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));

	return 0;
} /* main() */

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

/* Stack */
void initStack(Stack *s) {
	s->top = -1;
}

int isFullStack(Stack *s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

int isEmptyStack(Stack *s) {
	return (s->top == -1);
}

void push(Stack *s, element item) {
	if (isFullStack(s)) {
		error("Stack is Full!\n");
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(Stack *s) {
	if (isEmptyStack(s)) {
		error("Stack is Empty!\n");
	}
	else {
		return s->data[(s->top)--];
	}
}

void initQueue(Queue *q) {
	initStack(&q->s1);
	initStack(&q->s2);
}

int isFullQueue(Queue *q) {
	return isFullStack(&q->s1);
}

int isEmptyQueue(Queue *q) {
	return isEmptyStack(&q->s2);
}

void enqueue(Queue *q, element item) {
	if (isFullQueue(q)) {
		error("Queue is Full!\n");
	}
	else {
		push(&q->s1, item);
	}
}

element dequeue(Queue *q) {
	if (isEmptyQueue(q)) {
		while(!isEmptyStack(&q->s1)) {
			push(&q->s2, pop(&q->s1));
		}
	}

	if (isEmptyQueue(q)) {
		error("Queue is Empty!\n");
	}
	else {
		return pop(&q->s2);
	}
}
