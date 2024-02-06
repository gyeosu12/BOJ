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
int main(void)
{
    int N;
    scanf("%d", &N);
    long long int arr[100000];
    for (int i = 0; i < N; i++)
        scanf("%lld", arr + i);
    qsort(arr, N, sizeof(arr[0]), compare);
    int c = 1;
    int m_c = 0;
    long long int ans;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] == arr[i + 1])
            c++;
        else c = 1;
        if (c > m_c) {
            m_c = c;
            ans = arr[i];
        }
    }
    if (N == 1)
        ans = arr[0];

    printf("%lld", ans);
}