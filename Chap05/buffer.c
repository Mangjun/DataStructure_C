#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
	Queue queue;
	element number;

	initQueue(&queue);
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {
			enqueue(&queue, (rand() % 100) + 1);
		}
		queuePrint(&queue);
		if (rand() % 10 == 0) {
			int data = dequeue(&queue);
		}
		queuePrint(&queue);
	}

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
