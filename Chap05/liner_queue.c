#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} Queue;

void error(char *message);
void initQueue(Queue *q);
void queuePrint(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, element item);
element dequeue(Queue *q);

int main() {
	element item = 0;
	Queue q;

	initQueue(&q);

	enqueue(&q, 10); queuePrint(&q);
	enqueue(&q, 20); queuePrint(&q);
	enqueue(&q, 30); queuePrint(&q);

	item = dequeue(&q); queuePrint(&q);
	item = dequeue(&q); queuePrint(&q);
	item = dequeue(&q); queuePrint(&q);

	return 0;
}

/* transfer macros...? */
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initQueue(Queue *q) {
	q->front = -1;
	q->rear = -1;
}

void queuePrint(Queue *q) {
	if (isEmpty(q)) {
		return;
	}

	int front = q->front;
	int rear = q->rear;

	for (int i = front + 1; i <= rear; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int isFull(Queue *q) {
	return (q->rear == (MAX_QUEUE_SIZE - 1));
}

int isEmpty(Queue *q) {
	return (q->front == q->rear);
}

void enqueue(Queue *q, element item) {
	if (isFull(q)) {
		error("Queue is Full!\n");
	}	
	else {
		q->data[++(q->rear)] = item;
	}
}

element dequeue(Queue *q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
	}
	else {
		return q->data[++(q->front)];
	}
}
