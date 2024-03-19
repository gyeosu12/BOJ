#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int A, int B)
{
    if (A > B)return A;
    else return B;
}

int dp[101][100001];
int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    int v[101];
    int w[101];
    for (int i = 1; i <= N; i++)
        scanf("%d %d", w + i, v + i);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - w[i] >= 0)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[N][K]);
}