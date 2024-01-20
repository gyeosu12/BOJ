#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int dp[301];
int a[301];
int max(int A, int B)
{
	if (A > B)return A;
	else return B;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = a[1] + a[2];
	if (n == 1) {
		printf("%d", a[0]);
		return 0;
	}
	if (n == 2) {
		printf("%d", dp[1]);
		return 0;
	}
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]);
	}
	printf("%d", dp[n - 1]);
}