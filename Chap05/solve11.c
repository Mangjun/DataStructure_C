#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 20

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} Deque;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initDeque(Deque *q);
int isEmpty(Deque *q);
int isFull(Deque *q);
void dequePrint(Deque *q);
void addRear(Deque *q, element item);
element deleteFront(Deque *q);
element getFront(Deque *q);
void addFront(Deque *q, element item);
element deleteRear(Deque *q);
element getRear(Deque *q);

int isAlpha(char ch);
char lowwer(char ch);
int isPalindrome(Deque *q, char *message);

int main() {
	Deque queue;

	initDeque(&queue);

	char *message = "aadaslas";

	if (isPalindrome(&queue, message)) {
		printf("Palindrome!\n");
	}
	else {
		printf("Not palindrome!\n");
	}	

	return 0;
}

void initDeque(Deque *q) {
	q->front = q->rear = 0;
}
int isEmpty(Deque *q) {
	return (q->front == q->rear);
}

int isFull(Deque *q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

void dequePrint(Deque *q) {
	printf("Deque(front = %d, rear = %d)\n", q->front, q->rear);
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d ", q->data[i]);
			if (i == q->rear) {
				break;
			}
		} while (i != q->front);
	}
	printf("\n");
}

void addRear(Deque *q, element item) {
	if (isFull(q)) {
		error("Deque is Full!\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[(q->rear)] = item;
	}
}

element deleteFront(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[(q->front)];
	}
}

element getFront(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		return q->data[((q->front + 1) % MAX_QUEUE_SIZE)];
	}
}

void addFront(Deque *q, element item) {
	if (isFull(q)) {
		error("Deque is Full!\n");
	}
	else {
		q->data[(q->front)] = item;
		q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
}

element deleteRear(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		element val = q->data[(q->rear)];
		q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return val;	
	}
}

element getRear(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		return q->data[(q->rear)];
	}
}

int isAlpha(char ch) {
	return (ch >= 65 && ch <= 128);
}

char lowwer(char ch) {
	if (ch >= 65 && ch <= 96) {
		ch += 32;
	}

	return ch;
}

int isPalindrome(Deque *q, char *message) {
	int len = strlen(message);
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		char ch = message[i];
		if (isAlpha(ch)) {
			ch = lowwer(ch);
			addRear(q, ch);
			cnt++;
		}
	}

	cnt = cnt / 2;

	for (int i = 0; i < cnt; i++) {
		char ch1 = deleteFront(q);
	        char ch2 = deleteRear(q);
		if (ch1 != ch2) {
			return 0;
		}
	}

	return 1;
}
