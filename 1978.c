#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N, num, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        for (int j = 2; j <= num; j++) {
            if (num == j)
                cnt++;
            if (num % j == 0)
                break;
        }
    }
    printf("%d", cnt);
}