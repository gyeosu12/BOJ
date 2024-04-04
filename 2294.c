#include <stdio.h>
#include <string.h>

int min(int A, int B)
{
    if (A < B)return A;
    else return B;
}

int coin[101];
int dp[10001];
int main(void)
{
    memset(dp, 10001, sizeof(dp));
    int n, k;
    dp[0] = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", coin + i);
        for (int j = coin[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if (dp[k] >= 10001)
        printf("-1\n");
    else
        printf("%d", dp[k]);
}