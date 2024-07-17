#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//마지막에 max 를 구하는게 아니라 순번마다 max 를 계산하는방법임
	//+로 처음부터가 아니라 끝에서 부터 계산해야됨
	//왜? 예제 4번을 보면 6,7이 아니라 6,8번이 더 큰 값을 내어주기 때문
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