#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize)
{
    int *most_visited = calloc(1, sizeof(int) * n);
    int i = 0, j = 0;
    int start = rounds[0], end = rounds[roundsSize - 1];

    if (start <= end) {
        for (i = start; i <= end; i++, j++) {
            most_visited[j] = i;
        }
    }
    if (start > end) {
        for (i = 1; i <= end; i++, j++) {
            most_visited[j] = i;
        }
        for (i = start; i <= n; i++, j++) {
            most_visited[j] = i;
        }
    }
    *returnSize = j;
    return most_visited;
    /* free most_visited */
}