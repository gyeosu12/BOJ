#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//������ �־������� ������ ù°���� for������ ����
//dp�� ù��° for������ �ʱ�ȭ>> dp�� ���ݱ��� �� �� ����
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
	memset(dp, 1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
	}
	printf("%d", arrmax(dp, N, 0));
}