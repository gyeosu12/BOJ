#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(int i)
{
    if (i == 1)
        return 1;
    return i * f(i - 1);
}
int main(void)
{
    int N;
    scanf("%d", &N);
    if (N == 0)
        printf("1\n");
    else
        printf("%d\n", f(N));
}