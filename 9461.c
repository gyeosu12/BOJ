#include <stdio.h>
#include <string.h>
int min(int A, int B)
{
	if (A < B)return A;
	else return B;
}
int main(void)
{
	int N;
	long long dp[101];
	long long ans[101];
	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		if (0 < n && n < 4) {
			ans[i] = 1;
			continue;
		}
		if (3 < n && n < 6) {
			ans[i] = 2;
			continue;
		}
		for (int j = 5; j < n; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		ans[i] = dp[n - 1];
	}
	for (int i = 0; i < N; i++)
		printf("%lld\n", ans[i]);
}