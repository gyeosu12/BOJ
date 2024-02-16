#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int cnt = 0;
    scanf("%d", &N);
    for (int i = N; i > 0; i--) {
        if (i % 125 == 0)
            cnt += 3;
        else if (i % 25 == 0)
            cnt += 2;
        else if (i % 5 == 0)
            cnt++;
    }
    printf("%d\n", cnt);
}