#include <stdio.h>

int array_min(int *arr, int size)
{
    int i;

    if (size <= 0) {
        return -1;
    }
    int min = arr[0];
    
    for (i = 1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int array_max(int *arr, int size)
{
    int i;
    if (size <= 0) {
        return -1;
    }
    int max = arr[0];
    
    for (i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize){
    int moments = 0;
    int left_max = array_max(left, leftSize);
    int right_min = array_min(right, rightSize);
    if (leftSize <= 0 && rightSize <= 0) {
        return moments;
    }
    if (leftSize <= 0) {
        return n - right_min;
    }
    if (rightSize <= 0) {
        return left_max;
    }
    return left_max > (n - right_min) ? left_max : (n - right_min);
}

int main(void)
{
    printf("hello world\n");

    return 0;
}