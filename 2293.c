#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin[101];
int dp[10001];
int n, k;

int main(void)
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", coin + i);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {//coin
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);
}