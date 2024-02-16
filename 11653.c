#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        if (N % i == 0) {
            printf("%d\n", i);
            N = N / i;
            i = 1;
        }
    }
}