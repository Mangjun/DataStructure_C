#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

/* stack func */
void initStack(StackType *s);
int isEmpty(StackType *s);
int isFull(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);

/* check parentheses */
int checkMatching(const char *in);

int main() {
	char *p = "{ A[(i+1)] = 0; }";
	if (checkMatching(p) == 1) {
		printf("%s check success\n", p);
	} else {
		printf("%s check fail\n", p);
	}
} /* main() */

void initStack(StackType *s) {
	s->top = -1;
}

int isEmpty(StackType *s) {
	return (s->top == -1);
}

int isFull(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
	if (isFull(s)) {
		fprintf(stderr, "stack is full!\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
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

int checkMatching(const char *in) {
	StackType s;
	char ch, open_ch;
	int n = strlen(in);
	initStack(&s);

	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
			case '(':
			case '{':
			case '[':
				push(&s, ch);
				break;
			case ')':
			case '}':
			case ']':
				if (isEmpty(&s)) {
					return 0;
				}
				else {
					open_ch = pop(&s);
					if ((open_ch == '(' && ch != ')') ||
						(open_ch == '{' && ch != '}') ||
						(open_ch == '[' && ch != ']')) {
						return 0;
					}
					break;
				}
		}
	}

	if (!isEmpty(&s)) {
		return 0;
	}

	return 1;
}
