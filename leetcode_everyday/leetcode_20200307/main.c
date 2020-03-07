#include <stdio.h>
#include <stdlib.h>

/* mono queue, max_front->max_rear keep decrease */
#define QUEUE_LEN 1024
struct max_queue {
    int value[QUEUE_LEN];
    int front;
    int rear;
    int max_value[QUEUE_LEN];
    int max_front;
    int max_rear;
};
struct max_queue *create_queue(void)
{
    struct max_queue *q = calloc(1, sizeof(struct max_queue));
    return q;
}
int queue_empty(struct max_queue *obj)
{
    return (obj->front == obj->rear);
}
int get_queue_max_value(struct max_queue *obj)
{
    return (queue_empty(obj) ? -1 : obj->max_value[obj->max_front]);
}
void enqueue(struct max_queue *obj, int value)
{
    /* while max_value not empty, keep queue decrease */
    while (obj->max_front != obj->max_rear) {
        obj->max_rear = (obj->max_rear + QUEUE_LEN - 1) % QUEUE_LEN;
        if (value <= obj->max_value[obj->max_rear]) {
            obj->max_rear = (obj->max_rear + 1) % QUEUE_LEN;
            break;
        }
    }
    obj->max_value[obj->max_rear] = value;
    obj->max_rear = (obj->max_rear + 1) % QUEUE_LEN;

    obj->value[obj->rear] = value;
    obj->rear = (obj->rear + 1) % QUEUE_LEN;
}
int dequeue(struct max_queue *obj)
{
    int value;

    if (queue_empty(obj)) {
        return -1;
    }
    value = obj->value[obj->front];
    obj->front = (obj->front + 1) % QUEUE_LEN;

    if (value == obj->max_value[obj->max_front]) {
        obj->max_front = (obj->max_front + 1) % QUEUE_LEN;
    }
    return value;
}
void free_queue(struct max_queue *obj)
{
    free(obj);
    obj = NULL;
}
void print_queue(struct max_queue *obj)
{
    int i;

    for (i = obj->front; i < obj->rear; i++) {
        printf("%d, ", obj->value[i]);
    }
    printf("\n");
    for (i = obj->max_front; i < obj->max_rear; i++) {
        printf("%d, ", obj->max_value[i]);
    }
    printf("\n");
}
int main(void)
{
    struct max_queue *obj = create_queue();

    enqueue(obj, 1);
    print_queue(obj);
    enqueue(obj, 2);
    print_queue(obj);
    enqueue(obj, 4);
    print_queue(obj);
    enqueue(obj, 3);
    print_queue(obj);
    enqueue(obj, 5);
    print_queue(obj);
    enqueue(obj, 5);
    print_queue(obj);
    enqueue(obj, 4);
    print_queue(obj);
    return 0;
}
