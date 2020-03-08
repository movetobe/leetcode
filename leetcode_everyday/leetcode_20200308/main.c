/*
 * coin change
 * https://leetcode-cn.com/problems/coin-change/
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int coin(int* coins, int coinsSize, int amount, int *cache){
    int i;
    int cost = 0, min_cost = INT_MAX;

    if (amount == 0) {
        return 0;
    }

    for (i = 0; i < coinsSize; i++) {
        if (amount - coins[i] < 0) {
            continue;
        }
        if (cache[amount - coins[i]] >= 0) {
            cost = cache[amount - coins[i]];
        } else {
            cost = coin(coins, coinsSize, amount - coins[i], cache);
        }
        if (cost < INT_MAX) {
            min_cost = MIN(cost + 1, min_cost);
        }
    }
    cache[amount] = min_cost;
    return (min_cost < INT_MAX ? min_cost : -1);
}

int compare(const void *p1, const void *p2)
{
    return (*(int *)p2 - *(int *)p1);
}
int coinChange(int* coins, int coinsSize, int amount){
    qsort(coins, coinsSize, sizeof(int), compare);
    int *cost = calloc(1, sizeof(int) * (amount + 1));
    memset(cost, -1, sizeof(int) * (amount + 1));
    int num = coin(coins, coinsSize, amount, cost);
    free(cost);
    return num;
}

int main(void)
{
    int coins[128] = {0};
    int amount;
    int coins_size;
    int i;

    scanf("%d", &coins_size);
    for (i = 0; i < coins_size; i++) {
        scanf("%d", &coins[i]);
    }
    scanf("%d", &amount);
    printf("%d\n", coinChange(coins, coins_size, amount));
    return 0;
}
