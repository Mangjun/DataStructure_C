#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *top;
} Stack;

void init(Stack *stack);
void push(Stack* stack, element data);
int isEmpty(Stack* stack);
element pop(Stack* stack);
element peek(Stack* stack);
void printStack(Stack *stack);

int main() {
	Stack stack;

	init(&stack);

	push(&stack, 10); printStack(&stack);
	push(&stack, 20); printStack(&stack);
	push(&stack, 30); printStack(&stack);

	pop(&stack); printStack(&stack);
	pop(&stack); printStack(&stack);
	pop(&stack); printStack(&stack);

	return 0;
}

void init(Stack *stack) {
	stack->top = NULL;
}

void push(Stack* stack, element data) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = stack->top;

	stack->top = new_node;
}

int isEmpty(Stack* stack) {
	return (stack->top == NULL);
}

element pop(Stack* stack) {
	if (isEmpty(stack)) {
		fprintf(stderr, "%s\n", "Stack is Empty!\n");
		exit(1);
	}
	
	Node *removed = stack->top;
	element data = removed->data;
	stack->top = stack->top->next;
	free(removed);

	return data;
}

element peek(Stack* stack) {
	if (isEmpty(stack)) {
		fprintf(stderr, "%s\n", "Stack is Empty!\n");
		exit(1);
	}

	return stack->top->data;
}

void printStack(Stack *stack) {
	Node *index = stack->top;

	if (index == NULL) {
		return;
	}

	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}	
	printf("%d\n", index->data);
}
