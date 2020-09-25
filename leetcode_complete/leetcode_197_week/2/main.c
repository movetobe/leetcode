#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD_NUM (1000000007)
unsigned long calc_num(int sublen) {
    unsigned long len = sublen;
    unsigned long num = (((1 + len) * len) / 2) % MOD_NUM;
    return num;
}
int numSub(char * s)
{
    int i;
    unsigned long nums = 0;
    int sublen = 0;

    for (i = 0; i < strlen(s); i++) {
        if ((s[i] == '0') && (sublen > 0)) {
            nums += calc_num(sublen);
            sublen = 0;
            continue;
        }
        if (s[i] == '1') {
            sublen++;
        }
    }
    if (sublen > 0) {
        nums += calc_num(sublen);
    }
    return nums % MOD_NUM;
}

int main(void)
{
    char s[1024] = {0};
    scanf("%s", s);
    printf("%d\n", numSub(s));
}