#include <stdio.h>
#include <stdlib.h>

struct node {
    int child_size;
    int index;
    int *childs;
};
double jump_success(struct node *parents, int from, int start, int t, int target)
{
    int i;
    double possible = 0.0;

    /* end */
    if (t < 0) {
        return 0.0;
    }
    if ((t == 0) && (start == target)) {
        return 1.0;
    }
    /* leaf */
    if (parents[start].child_size <= 1) {
        return (start == target ? 1.0 : 0.0);
    }

    /* options */
    for (i = 0; i < parents[start].child_size; i++) {
        if (parents[start].childs[i] != from) {
            possible += jump_success(parents, start, parents[start].childs[i], t - 1, target);
        }
    }
    return possible / (parents[start].child_size - 1);
}
double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    int i, j;
    double possible = 0.0;
    struct node *parents;
    int index1, index2;
    int begin = 1;

    n  = n + 1;
    parents = calloc(1, sizeof(struct node) * n);
    for (i = 0; i < edgesSize; i++) {
        parents[edges[i][0]].child_size++;
        parents[edges[i][1]].child_size++;
    }
    parents[begin].child_size++;
    for (i = 0; i < n; i++) {
        parents[i].childs = calloc(1, sizeof(int) * parents[i].child_size);
    }
    for (i = 0; i < edgesSize; i++) {
        index1 = parents[edges[i][0]].index;
        index2 = parents[edges[i][1]].index;
        parents[edges[i][0]].childs[index1] = edges[i][1];
        parents[edges[i][1]].childs[index2] = edges[i][0];
        parents[edges[i][0]].index++;
        parents[edges[i][1]].index++;
    }
    /* begin is from -1 */
    parents[begin].childs[parents[begin].index] = -1;
    parents[begin].index++;
    possible = jump_success(parents, -1, begin, t, target);

    for (i = 0; i < n; i++) {
        free(parents[i].childs);
    }
    free(parents);
    return possible;
}
int main(void)
{
    int n, t, target, edgesSize;
    int **edges, *edgesColSize;
    int i;

    scanf("%d %d %d %d", &n, &t, &target, &edgesSize);
    edges = calloc(1, sizeof(int *) * edgesSize);
    edgesColSize = calloc(1, sizeof(int) * edgesSize);
    edgesColSize[0] = 2;
    for (i = 0; i < edgesSize; i++) {
        edgesColSize[i] = 2;
        edges[i] = calloc(1, sizeof(int) * 2);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    printf("%f\n", frogPosition(n, edges, edgesSize, edgesColSize, t, target));
    /* free everythiing */
    return 0;
}