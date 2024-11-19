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

/* transfer postfix */
int prec(char op);
void infixToPostfix(char exp[]);

/* postfix calc */
int eval(char exp[]);

int main() {
	char *s = "(2+3)*4+9";
	printf("before : %s\n", s);
	printf("after : ");
	infixToPostfix(s);

	return 0;
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

int eval(char exp[]) {
	int op1, op2, value;
	int len = strlen(exp);
	char ch;
	StackType s;

	initStack(&s);

	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);

			switch (ch) {
				case '+':
					push(&s, (op1 + op2));
					break;
				case '-':
					push(&s, (op1 - op2));
					break;
				case '*':
					push(&s, (op1 * op2));
					break;
				case '/':
					push(&s, (op1 / op2));
					break;
			}
		}
	}

	return pop(&s);
}

int prec(char op) {
	switch (op) {
		case '(':
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return -1;
	}
}

void infixToPostfix(char exp[]) {
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	initStack(&s);
	for (int i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
			case '+':
			case '-':
			case '*':
			case '/':
				while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {
					printf("%c", pop(&s));
				}
				push(&s, ch);
				break;
			case '(':
				push(&s, ch);
				break;
			case ')':
				top_op = pop(&s);
				while (top_op != '(') {
					printf("%c", top_op);
					top_op = pop(&s);
				}
				break;
			default:
				printf("%c", ch);
				break;
		}
	}

	while (isEmpty(&s)) {
		printf("%c", pop(&s));
	}

	printf("\n");
}
