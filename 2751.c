#include <stdio.h>
#include <string.h>
/*int min(int A, int B)
{
    if (A < B)return A;
    else return B;
}
*/
void merge(int a[], int fir, int mid, int end)
{
    int b[1000000];
    int i = fir;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= end)
        b[k++] = a[j++];
    k--;
    while (k >= 0)
    {
        a[fir + k] = b[k];
        k--;
    }
}
void mergesort(int a[], int fir, int end)
{

    if (fir < end) {
        int mid = (fir + end) / 2;
        mergesort(a, fir, mid);
        mergesort(a, mid + 1, end);
        merge(a, fir, mid, end);
    }
}
int main(void)
{
    int N;
    int dp[1000000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &dp[i]);
    mergesort(dp, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%d ", dp[i]); //"%d "°¡ ÇÙ½É
}