#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_max_target(int *target, int targetSize, int *locate)
{
	int i;
	long max = 0;

	for (i = 0; i < targetSize; i++) {
		if (target[i] > max) {
			max = target[i];
			*locate = i;
		}
	}
	return max;
}
int isPossible(int* target, int targetSize)
{
	int locate;
	long max, sum = 0;

	for (locate = 0; locate < targetSize; locate++) {
		sum += target[locate];
	}

	for (;;) {
		max = get_max_target(target, targetSize, &locate);
		if ((max == 1) && (sum == targetSize)) {
			return 1;
		}
		if (max - (sum - max) <= 0) {
			return 0;
		}
		target[locate] = max - (sum - max);
		sum = max;
	}
}
int main(void)
{
	int target[1024] = {0};
	int targetSize;

	scanf("%d", &targetSize);
	int i = 0;
	for (i = 0; i < targetSize; i++) {
		scanf("%d,", &target[i]);
	}
	printf("%d\n", isPossible(target, targetSize));
}
