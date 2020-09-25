#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2)
{
    return *((int *)p1) - *((int *)p2);
}
bool canMakeArithmeticProgression(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), compare);
    int i = 0;
    int devition = arr[1] - arr[0];
    for (i = 2; i < arrSize; i++) {
        if (devition != (arr[i] - arr[i - 1])) {
            return false;
        }
    }
}