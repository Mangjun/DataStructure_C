#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;

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
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;

	Queue queue;
	initQueue(&queue);	

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("current time : %d\n", clock);
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("customer%d is coming at %dmin. processing time : %dmin\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("customer%d processing...\n", service_customer);
			service_time--;
		}
		else {
			if (!isEmpty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("customer%d start task at %dmin. waiting time : %d\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("total waiting time : %d\n", total_wait);
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
			printf("%d ", q->data[i].id);
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
