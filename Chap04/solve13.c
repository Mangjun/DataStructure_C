#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

void initStack(Stack *s) {
	s->top = -1;
}

int isFull(Stack *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

int isEmpty(Stack *s) {
	return (s->top == -1);
}

void push(Stack *s, element item) {
	if (isFull(s)) {
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(Stack *s) {
	if (isEmpty(s)) {
		return -1;
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(Stack *s) {
	if (isEmpty(s)) {
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

int main() {
	char str[MAX_STACK_SIZE];
	Stack s;
	int len;

	printf("input number : ");
	scanf("%s", str);

	initStack(&s);
	len = strlen(str);

	printf("print : ");
	for (int i = 0; i < len; i++) {
		element ch = str[i] - '0';
		
		if (isEmpty(&s)) {
			push(&s, ch);
		} else {
			element peek_ch = peek(&s);

			if (peek_ch != ch) {
				printf("%d", pop(&s));
			}
		}
	}
	
	if (!isEmpty(&s)) {
		printf("%d", pop(&s));
	}

	printf("\n");
	return 0;
}
