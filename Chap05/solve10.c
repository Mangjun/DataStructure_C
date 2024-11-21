#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} Queue;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void queuePrint(Queue *q);
void enqueue(Queue *q, element item);
element dequeue(Queue *q);
element peek(Queue *q);

int fibonacci(Queue *q, int n);

int main() {
	Queue queue;

	initQueue(&queue);

	int n = 10;
	printf("fibonacci %d : %d\n", n, fibonacci(&queue, n));

	return 0;
}

void initQueue(Queue *q) {
	q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
	return (q->front == q->rear);
}

int isFull(Queue *q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

void queuePrint(Queue *q) {
	printf("Queue(front = %d, rear = %d)\n", q->front, q->rear);
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

void enqueue(Queue *q, element item) {
	if (isFull(q)) {
		error("Queue is Full!\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(Queue *q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

element getFront(Queue *q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
	}
	else {
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}

element getRear(Queue *q) {
	if (isEmpty(q)) {
		error("Queue is Empty!\n");
	}
	else {
		return q->data[q->rear];
	}
}

int fibonacci(Queue *q, int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;

	int val;
	enqueue(q, 0);
	enqueue(q, 1);

	for (int i = 3; i <= n; i++) {
		val = dequeue(q);
		enqueue(q, val + getFront(q));
		queuePrint(q);
	}
	
	return getRear(q);	
}
