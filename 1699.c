#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int min(int A, int B)
{
	if (A < B)return A;
	else return B;
}
int main(void)
{
	int dp[100001];
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)dp[i] = i;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	printf("%d", dp[n]);
}