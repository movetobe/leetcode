#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *closestDivisors(int num, int *returnSize)
{
	int *return_array = calloc(1, sizeof(int) * 2);
	int start1 = sqrt(num + 1);
	int start2 = sqrt(num + 2);

	*returnSize = 2;
	for (; start1 > 0; start1--) {
		if ((num + 1) % start1 == 0) {
			return_array[0] = start1;
			return_array[1] = (num + 1) / start1;
			break;
		}
	}
	for (; start2 > 0; start2--) {
		if ((num + 2) % start2 == 0) {
			if (start2 > start1) {
				return_array[0] = start2;
				return_array[1] = (num + 2) / start2;
			}
			break;
		}
	}
	return return_array;
}

int main(void)
{
	int num;
	int *return_array;
	int returnSize;

	scanf("%d", &num);

	return_array = closestDivisors(num, &returnSize);
	printf("[%d, %d]\n", return_array[0], return_array[1]);

	free(return_array);

	return 0;
}
