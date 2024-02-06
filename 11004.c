#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(void* a, void* b)
{
    long long int* pa = (long long int*)a;
    long long int* pb = (long long int*)b;
    if (*pa > *pb)
        return 1;
    else if (*pa < *pb)
        return -1;
    else
        return 0;
}
long long int arr[5000000];
int main(void)
{

    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%lld", arr + i);
    qsort(arr, N, sizeof(arr[0]), compare);
    printf("%lld", arr[K - 1]);
}