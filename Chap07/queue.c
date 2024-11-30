#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *front, *rear;
} Queue;

void init(Queue *queue);
void enqueue(Queue *queue, element data);
int isEmpty(Queue *queue);
element dequeue(Queue *queue);
void printQueue(Queue *queue);

int main() {
	Queue queue;

	init(&queue);

	enqueue(&queue, 10); printQueue(&queue);
	enqueue(&queue, 20); printQueue(&queue);
	enqueue(&queue, 30); printQueue(&queue);
	
	dequeue(&queue); printQueue(&queue);
	dequeue(&queue); printQueue(&queue);
	dequeue(&queue); printQueue(&queue);

	return 0;
}

void init(Queue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

void enqueue(Queue *queue, element data) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	if (isEmpty(queue)) {
		queue->front = new_node;
		queue->rear = new_node;
	} else {
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

int isEmpty(Queue *queue) {
	return (queue->front == NULL);
}

element dequeue(Queue *queue) {
	if (isEmpty(queue)) {
		fprintf(stderr, "%s\n", "Queue is Empty!");
		exit(1);
	}

	Node *removed = queue->front;
	element data = removed->data;
	queue->front = queue->front->next;
	free(removed);
	
	return data;
}

void printQueue(Queue *queue) {
	Node *index = queue->front;

	if (index == NULL) {
		printf("Queue is Empty\n");
		return;
	}

	while (index->next != NULL) {
		printf("%d->", index->data);
		index = index->next;
	}
	printf("%d\n", index->data);
}
