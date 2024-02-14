#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char N[1000002];
int main(void)
{
    scanf("%s", N);
    int a = strlen(N);
    if (a % 3 == 2)
        printf("%d", (int)(N[0] - '0') * 2 + (N[1] - '0') * 1);
    else if (a % 3 == 1)
        printf("%d", (int)(N[0] - '0') * 1);
    for (int i = a % 3; i < a; i += 3) {
        printf("%d", (int)(N[i + 2] - '0') * 1 + (N[i + 1] - '0') * 2 + (N[i] - '0') * 4);
    }
}