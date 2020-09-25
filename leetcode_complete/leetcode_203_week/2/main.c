#include <stdio.h>
#include <stdlib.h>


int compare(const void *p1, const void *p2)
{
    return (*(int *)p2 - *(int *)p1);
}
int maxCoins(int* piles, int pilesSize)
{
    int i = 0;
    int max_coins = 0;
    int left = pilesSize;

    qsort(piles, pilesSize, sizeof(int), compare);
    for (i = 0; i < pilesSize; i += 2) {
        max_coins += piles[i + 1];
        left -= 3;
        if (left <= 0) {
            break;
        }
    }
    return max_coins;
}

int main(void)
{
    int pilesSize;
    scanf("%d\n", &pilesSize);
    int *piles = calloc(1, sizeof(int) * pilesSize);
    int i;
    for (i = 0; i < pilesSize; i++) {
        scanf("%d", &piles[i]);
    }
    printf("%d\n", maxCoins(piles, pilesSize));
}