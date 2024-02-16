#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//에라토스테네스의 채 사용
int main(void)
{
    int M, N;
    int arr[1000001] = { 0, };
    arr[1] = 1;
    scanf("%d %d", &M, &N);
    for (int i = 2; i <= N; i++)
        for (int j = 2; j * i <= N; j++)
            arr[i * j] = 1;
    for (int i = M; i <= N; i++)
        if (arr[i] == 0)
            printf("%d\n", i);
}