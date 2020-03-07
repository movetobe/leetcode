int compare(const void *p1, const void *p2)
{
	return (*(int *)p1 - *(int *)p2);
}

int minSetSize(int* arr, int arrSize){
	int max = 0;
	int i;
	int *count;
	int least_range = 0;
	int sum = 0;

	for (i = 0; i < arrSize; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	count = calloc(1, sizeof(int) * (max + 1));

	for (i = 0; i < arrSize; i++) {
		count[arr[i]]++;
	}
	qsort(count, max + 1, sizeof(int), compare);

	for (i = 0; i <= max; i++) {
		if (sum >= (arrSize / 2)) {
			break;
		}
		if (count[i] > 0) {
			least_range++;
			sum += count[i];
		}
	}
	free(count);

	return least_range;
}
