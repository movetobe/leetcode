#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int days(char *date)
{
	int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y = 0, m = 0, d = 0;
	int i = 0;
	int days = 0;

	for (i = 0; i < 4; i++) {
		y = y * 10 + (date[i] - '0');
	}
	for (i = 5; i < 7; i++) {
		m = m * 10 + (date[i] - '0');
	}
	for (i = 8; i < 10; i++) {
		d = d * 10 + (date[i] - '0');
	}

	for (i = 1970; i < y; i++) {
		if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0))) {
			days += 366;
		} else {
			days += 365;
		}
	}

	if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) {
		days_per_month[2] = 29;
	}
	for (i = 1; i < m; i++) {
		days += days_per_month[i];
	}
	days += d;

	return days;
}

int daysBetweenDates(char *date1, char *date2)
{
	return abs(days(date1) - days(date2));	
}
int main(void)
{
	char date1[12] = {0};
	char date2[12] = {0};

	scanf("%s", date1);
	scanf("%s", date2);

	printf("%d\n", daysBetweenDates(date1, date2));

	return 0;
}
