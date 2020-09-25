#include <stdio.h>
#include <stdlib.h>

struct node {
    int prev;
    int next;
};
int findLatestStep(int* arr, int arrSize, int m)
{
    int i;
    struct node *nodes = calloc(1, sizeof(struct node) * (arrSize + 2));
    int put_index;
    int last_step = -1;
    int count = 0;

    for (i = 0; i < arrSize + 2; i++) {
        nodes[i].prev = -1;
        nodes[i].next = -1;
    }
    for (i = 0; i < arrSize; i++) {
        put_index = arr[i];
        if (nodes[put_index - 1].prev != -1 && nodes[put_index + 1].next != -1) {
            nodes[put_index].prev = nodes[put_index - 1].prev;
            nodes[put_index].next = nodes[put_index + 1].next;
            nodes[nodes[put_index - 1].prev].next = nodes[put_index + 1].next;
            nodes[nodes[put_index + 1].next].prev = nodes[put_index - 1].prev;
        }
        if (nodes[put_index - 1].prev != -1 && nodes[put_index + 1].next == -1) {
            nodes[put_index].prev = nodes[put_index - 1].prev;
            nodes[put_index].next = put_index;
            nodes[nodes[put_index - 1].prev].next = put_index;
        }
        if (nodes[put_index - 1].prev == -1 && nodes[put_index + 1].next != -1) {
            nodes[put_index].prev = put_index;
            nodes[put_index].next = nodes[put_index + 1].next;
            nodes[nodes[put_index + 1].next].prev = put_index;
        }
        if (nodes[put_index - 1].prev == -1 && nodes[put_index + 1].next == -1) {
            nodes[put_index].prev = put_index;
            nodes[put_index].next = put_index;
        }
        if (nodes[put_index].next - put_index == m) {
            count--;
        }
        if (put_index - nodes[put_index].prev == m) {
            count--;
        }
        if (nodes[put_index].next - nodes[put_index].prev + 1 == m) {
            count++;
        }
        if (count > 0) {
            last_step = i + 1;
        }
    }
    return last_step;
}