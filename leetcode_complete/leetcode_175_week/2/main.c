#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_steps(char *s, char *t)
{
	int i;
	int steps = 0;
	int alpha[256] = {0};

	for (i = 0; i < strlen(s); i++) {
		alpha[s[i]]++;
	}

	for (i = 0; i < strlen(t); i++) {
		if (alpha[t[i]] > 0) {
			alpha[t[i]]--;
		}
	}

	for (i = 0; i < 256; i++) {
		steps += alpha[i];
	}

	return steps;
}

int main(void)
{
	char s[1024] = {0};
	char t[1024] = {0};

	scanf("%s", s);
	scanf("%s", t);

	printf("%d\n", min_steps(s, t));

	return 0;
}
