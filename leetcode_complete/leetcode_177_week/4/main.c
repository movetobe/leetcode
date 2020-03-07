#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiple_of_three(int *digits, int digitsSize, int *visited)
{
	int i = 0;
	int sum = 0;

	for (i = 0; i < digitsSize; i++) {
		if (!visited[i]) {
			sum += digits[i];
		}
	}

	if (sum % 3 == 0) {
		return 1;
	}

	for (i = 0; i < digitsSize; i++) {
		if ((!visited[i]) && (digits[i] > 0)) {
			visited[i] = 1;
			if (multiple_of_three(digits, digitsSize, visited)) {
				return 1;
			}
			visited[i] = 0;
		}
	}
	return 0;
}

int compare(const void *p1, const void *p2)
{
	return ((*(int *)p1) - (*(int *)p2));
}
char * largestMultipleOfThree(int* digits, int digitsSize)
{
	int *visited = calloc(1, sizeof(int) * digitsSize);
	int i = 0, j = 0;
	char *return_array = calloc(1, sizeof(char) * digitsSize);

	qsort(digits, digitsSize, sizeof(int), compare);
	if (!multiple_of_three(digits, digitsSize, visited)) {
		free(visited);
		return return_array;
	}

	for (i = digitsSize - 1; i >= 0; i--) {
		if (!visited[i]) {
			return_array[j] = digits[i] + '0';
			j++;
		}
	}
	if (return_array[0] == '0') {
		return_array[1] = '\0';
	}
	free(visited);
	return return_array;
}

int main(void)
{
	int digits[1024] = {0};
	int digitsSize = 0;
	int i = 0;

	scanf("%d", &digitsSize);
	for (i = 0; i < digitsSize; i++) {
		scanf("%d", &digits[i]);
	}

	printf("%s\n", largestMultipleOfThree(digits, digitsSize));

	/* should free return_array */
	return 0;
}
