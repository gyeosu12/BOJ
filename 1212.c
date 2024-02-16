#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char N[1000002];
int main(void)
{
    char* num[8] = { "000","001","010","011","100","101","110","111" };
    scanf("%s", N);
    int n = strlen(N);
    for (int i = 0; i < n; i++) {
        int a = N[i] - '0';
        if (i == 0)printf("%d", atoi(num[a]));
        else printf("%s", num[a]);
    }
}