#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1, const void *p2)
{
	int **event1 = (int **)p1;
	int **event2 = (int **)p2;

	if (event1[0][1] != event2[0][1]) {
		return event1[0][1] - event2[0][1];
	}
	return event1[0][0] - event2[0][0];
}
int maxEvents(int** events, int eventsSize, int* eventsColSize){
	
	qsort(events, eventsSize, sizeof(int) * eventsColSize[0], compare);
	int *join = calloc(1, sizeof(int) * 100000);
	int i, j;
	int count = 0;

	for (i = 0; i < eventsSize; i++) {
		for (j = events[i][0]; j <= events[i][1]; j++) {
			if (!join[j]) {
				join[j] = 1;
				count++;
				break;
			}
		}
	}
	free(join);
	return count;
}

int main(void)
{
	int eventsSize;
	scanf("%d", &eventsSize);
	int *eventsColSize = calloc(1, sizeof(int) * eventsSize);
	int **events = calloc(1, sizeof(int *) * eventsSize);
	int i;
	for (i = 0; i < eventsSize; i++) {
		events[i] = calloc(1, sizeof(int) * 2);

		eventsColSize[i] = 2;
		scanf("%d %d", &events[i][0], &events[i][1]);
	}

	printf("%d\n", maxEvents(events, eventsSize, eventsColSize));
	return 0;
}

