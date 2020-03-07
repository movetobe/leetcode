#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_DEPTH 10240 
struct queue {                                                                     
    int value[QUEUE_DEPTH];                                                        
    int rear;                                                                      
    int front;                                                                     
};

int queue_init(struct queue *q)
{
	memset(q, 0, sizeof(struct queue));

	return 0;
}

int queue_empty(struct queue *q)
{
	if (q->rear == q->front) {
		return 1;
	}
	return 0;
}

int queue_full(struct queue *q)
{
	if (((q->rear + 1) % QUEUE_DEPTH) == q->front) {
		return 1;
	}
	return 0;
}

int enqueue(struct queue *q, int value)
{
	if (queue_full(q)) {
		printf("queue full\n");
		return -1;
	}
	q->value[q->rear] = value;
	q->rear = (q->rear + 1) % QUEUE_DEPTH;

	return 0;
}

int dequeue(struct queue *q)
{
	int value = 0;

	if (queue_empty(q)) {
		printf("queue empty\n");
		return -1;
	}
	value = q->value[q->front];
	q->front = (q->front + 1) % QUEUE_DEPTH;

	return value;
}

int validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    int i = 0;
	struct queue q;
	int *visited = calloc(1, sizeof(int) * n);
	int count = 0;
	int next;
	int left_start = -1, right_start = -1;

	queue_init(&q);
    /* find root */
    for (i = 0; i < leftChildSize; i++) {
        if ((leftChild[i] >= 0) && (left_start < 0)) {
            left_start = i;
        }
        if ((rightChild[i] >= 0) && (right_start < 0)) {
            right_start = i;
        }
        if ((left_start >= 0) || (right_start >= 0)) {
            break;
        }
    }
	if (left_start == right_start) {
		enqueue(&q, leftChild[left_start]);
		enqueue(&q, rightChild[right_start]);
		visited[left_start] = 1;
	} else if ((right_start < 0) || (left_start < right_start)) {
		enqueue(&q, leftChild[left_start]);
		visited[left_start] = 1;
	} else {
		enqueue(&q, rightChild[right_start]);
		visited[right_start] = 1;
	}
	count++;

	while (!queue_empty(&q)) {
		next = dequeue(&q);
		if (visited[next]) {
			return 0;
		}
		visited[next] = 1;
		count++;
		if (leftChild[next] >= 0) {
			enqueue(&q, leftChild[next]);
		}
		if (rightChild[next] >= 0) {
			enqueue(&q, rightChild[next]);
		}
	}
	return (count == n);
}

int main(void)
{
	int n = 5;
	int leftChild[5] = {0,-1,3,1,3};
	int rightChild[5] = {4,3,0,1,-1};

	printf("%d\n", validateBinaryTreeNodes(5, leftChild, 5, rightChild, 5));

	return 0;
}
