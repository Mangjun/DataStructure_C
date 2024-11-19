#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short row;
	short col;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void initStack(StackType *s) {
	s->top = -1;
}

element here = {1, 0}, entry = {1, 0};
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

/* Stack */
int isEmpty(StackType *s);
int isFull(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);

/* Maze */
void mazePrint(char maze[MAZE_SIZE][MAZE_SIZE]);
void pushLoc(StackType *s, int row, int col);

int main() {
	int row, col;
	StackType s;

	initStack(&s);
	here = entry;

	while (maze[here.row][here.col] != 'x') {
		row = here.row;
		col = here.col;
		maze[row][col] = '.';
		mazePrint(maze);
		pushLoc(&s, row - 1, col);
		pushLoc(&s, row + 1, col);
		pushLoc(&s, row, col - 1);
		pushLoc(&s, row, col + 1);

		if (isEmpty(&s)) {
			printf("fail\n");
			return -1;
		}
		else {
			here = pop(&s);
		}
	}

	printf("success\n");
	return 0;
} /* main() */


/* Stack */
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

/* Maze */
void mazePrint(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int row = 0; row < MAZE_SIZE; row++) {
		for (int col = 0; col < MAZE_SIZE; col++) {
			printf("%c ", maze[row][col]);
		}
		printf("\n");
	}
}

void pushLoc(StackType *s, int row, int col) {
	if (row < 0 || col < 0) return;
	if (maze[row][col] != '1' && maze[row][col] != '.') {
		element tmp;
		tmp.row = row;
		tmp.col = col;

		push(s, tmp);
	}
}
