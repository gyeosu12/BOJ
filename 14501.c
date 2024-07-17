#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//�������� max �� ���ϴ°� �ƴ϶� �������� max �� ����ϴ¹����
	//+�� ó�����Ͱ� �ƴ϶� ������ ���� ����ؾߵ�
	//��? ���� 4���� ���� 6,7�� �ƴ϶� 6,8���� �� ū ���� �����ֱ� ����
	int dp[16] = { 0, };
	int T[16] = { 0, };
	int P[16] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", T + i, P + i);
	}
	int dl;
	for (int i = n; i > 0; i--) {
		dl = T[i] + i;
		if (dl > n + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = Max(dp[i + 1], P[i] + dp[dl]);
	}
	printf("%d", dp[1]);
}