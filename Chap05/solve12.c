#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 20
#define MAX_CPU 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear, count;
} Deque;
typedef struct {
	Deque cpu[MAX_CPU];
	int count[MAX_CPU];
} Computer;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int max(int arr[]) {
	int index = 0;
	int max = arr[0];
	for (int i = 0; i < MAX_CPU; i++) {
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}
	}
	
	return index;
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

void initComputer(Computer *com);
void ASteal(Computer *com, int index);

int main() {
	Computer com;
	initComputer(&com);

	addRear(&com.cpu[0], 1);
	addRear(&com.cpu[0], 2);
	addRear(&com.cpu[0], 3);

	addRear(&com.cpu[1], 1);
	addRear(&com.cpu[1], 2);
	addRear(&com.cpu[1], 3);

	addRear(&com.cpu[2], 1);
	addRear(&com.cpu[2], 2);

	addRear(&com.cpu[3], 1);
	addRear(&com.cpu[3], 2);
	addRear(&com.cpu[3], 3);

	addRear(&com.cpu[4], 1);
	addRear(&com.cpu[4], 2);
	addRear(&com.cpu[4], 3);

	deleteFront(&com.cpu[2]);

	ASteal(&com, 2);

	return 0;
}

void initDeque(Deque *q) {
	q->front = q->rear = q->count = 0;
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
		(q->count)++;
	}
}

element deleteFront(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		(q->count)--;
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
		(q->count)++;
	}
}

element deleteRear(Deque *q) {
	if (isEmpty(q)) {
		error("Deque is Empty!\n");
	}
	else {
		element val = q->data[(q->rear)];
		q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		(q->count)--;
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

void initComputer(Computer *com) {
	for (int i = 0; i < MAX_CPU; i++) {
		initDeque(&com->cpu[i]);
		com->count[i] = 0;
	}
}

void ASteal(Computer *com, int index) {
	int max_index = max(&com->count);

	printf("before\n");
	for (int i = 0; i < MAX_CPU; i++) {
		printf("cpu %d : ", i + 1);
		dequePrint(&com->cpu[i]);
	}

	addRear(&com->cpu[index], deleteRear(&com->cpu[max_index]));

	printf("\nafter\n");
	for (int i = 0; i < MAX_CPU; i++) {
		printf("cpu %d : ", i + 1);
		dequePrint(&com->cpu[i]);
	}
}
