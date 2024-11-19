#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
	char data[MAX_STACK_SIZE];
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

void push(Stack *s, char ch) {
	if (isFull(s)) {
		return;
	}
	else {
		s->data[++(s->top)] = ch;
	}
}

char pop(Stack *s) {
	if (isEmpty(s)) {
		return -1;
	}
	else {
		return s->data[(s->top)--];
	}
}

char peek(Stack *s) {
	if (isEmpty(s)) {
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

char lowwerChar(char ch) {
	if (ch >= 65 && ch <= 96) {
		ch += 32;	
	}

	return ch;
}

int isAlphabet(char ch) {
	return (ch >= 65 && ch <= 128);
}

int main() {
	char str[MAX_STACK_SIZE];
	Stack s;
	int len;

	printf("input string : ");
	scanf("%s", str);

	initStack(&s);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (!isAlphabet(ch)) {
			continue;
		}

		ch = lowwerChar(ch);

		push(&s, ch);
	}

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (!isAlphabet(ch)) {
			continue;
		}

		ch = lowwerChar(ch);

		if (!(pop(&s) == ch)) {
			printf("Not\n");
			return 0;
		}
	}

	printf("Yes\n");
	return 0;
}
