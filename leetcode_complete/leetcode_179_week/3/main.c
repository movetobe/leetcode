#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int inform(int n, int headID, int *last_child, int *sibling, int *inform_time)
{
    int i = 0;
    int cost, max_cost = 0;

    if (inform_time[headID] == 0) {
        return 0;
    }
    for (i = last_child[headID]; i >= 0; i = sibling[i]) {
        cost = inform(n, i, last_child, sibling, inform_time) + inform_time[headID];
        max_cost = MAX(max_cost, cost);
    }
    return max_cost;
}
int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize)
{
    int i;
    int cost;
    int *last_child = calloc(1, sizeof(int) * n);
    int *sibling = calloc(1, sizeof(int) * n);

    memset(last_child, -1, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (i != headID) {
            sibling[i] = last_child[manager[i]];
            last_child[manager[i]] = i;
        }
    }
    cost = inform(n, headID, last_child, sibling, informTime);
    free(last_child);
    free(sibling);
    return cost;
}

int main(void)
{
    int manager[1024] = {0};
    int informTime[1024] = {0};
    int n;
    int headID;
    int managerSize;
    int informTimeSize;
    int i;

    scanf("%d %d %d %d", &n, &headID, &managerSize, &informTimeSize);
    for (i = 0; i < managerSize; i++) {
        scanf("%d", &manager[i]);
    }
    for (i = 0; i < informTimeSize; i++) {
        scanf("%d", &informTime[i]);
    }
    int num = numOfMinutes(n, headID, manager, managerSize, informTime, informTimeSize);
    printf("%d\n", num);
    return 0;
}