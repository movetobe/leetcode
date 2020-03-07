#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vote_class {
    char team;
    int tickets[26];
};
int compare(const void *p1, const void *p2)
{
    int i;
    struct vote_class *v1 = (struct vote_class *)p1;
    struct vote_class *v2 = (struct vote_class *)p2;
    
    for (i = 0; i < 26; i++) {
        if (v1->tickets[i] != v2->tickets[i]) {
            return (v2->tickets[i] - v1->tickets[i]);
        }
    }
    return 0;
}

char * rankTeams(char ** votes, int votesSize){
    int i, j;
    struct vote_class v[26];
    char *rank = calloc(1, sizeof(char) * (strlen(votes[0] + 1)));
    
    memset(v, 0, sizeof(struct vote_class) * 26);
    for (i = 0; i < votesSize; i++) {
        for (j = 0; j < strlen(votes[i]); j++) {
            v[votes[i][j] - 'A'].team = votes[i][j];
            v[votes[i][j] - 'A'].tickets[j]++;
        }
    }

    qsort(v, 26, sizeof(struct vote_class), compare);

    
    for (i = 0; i < strlen(votes[0]); i++) {
        rank[i] = v[i].team;
    }

    return rank;
 }

int main(void)
{
	char *votes[] = {"ABC", "BCA"};
	int votesSize = 2;

	printf("%s\n", rankTeams(votes, votesSize));

	return 0;
}
