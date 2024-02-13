#include <stdio.h>
#include <string.h>
int A[1001];
int arrmax(int arr[], int n, int s)
{
	int m = arr[s];
	for (int i = s; i < n; i++)
	{
		if (arr[i] > m)m = arr[i];
	}
	return m;
}
int max(int A, int B)
{
	if (A > B)return A;
	else return B;
}
int main(void)
{
	int N;
	int dp[1001];
	int mm = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < N; i++)
		dp[i] = A[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp[i] < dp[j] + A[i]) {
				dp[i] = dp[j] + A[i];
			}
		}
	}
	printf("%d", arrmax(dp, N, 0));
}