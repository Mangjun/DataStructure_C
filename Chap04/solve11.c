#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100


typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} Stack;

void initStack(Stack *s) {
	s->top = -1;
}

int isEmpty(Stack *s) {
	return (s->top == -1);
}

int isFull(Stack *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(Stack *s, int item) {
	if (isFull(s)) {
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

int pop(Stack *s) {
	if (isEmpty(s)) {
		return -1;
	}
	else {
		return s->data[(s->top)--];
	}
}

void clear(Stack *s) {
	s->top = -1;
}

void print(Stack *s, const char *str) {
	int cnt = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') { 
			printf("%d ", ++cnt);
			push(s, cnt);
		}
		else {
			printf("%d ", pop(s));
		}
	}

	printf("\n");
}

int main() {
	char *str = "((())(()))";
	char *str2 = "(((((()";

	Stack s;

	initStack(&s);
	print(&s, str);

	clear(&s);
	print(&s, str2);

	return 0;
}
