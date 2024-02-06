#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//count sort 이용 입력을 함과 동시에 정렬까지 가능 O[N] 보장
int main(void)
{
    int N;
    scanf("%d", &N);

    int count[10001] = { 0, };
    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        count[n] += 1;
    }
    for (int i = 0; i < 10001; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d\n", i);
}