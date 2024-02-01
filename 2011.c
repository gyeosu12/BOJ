#include <stdio.h>
#include <string.h>
int min(int A, int B)
{
	if (A < B)return A;
	else return B;
}
char dp[5001];
int ddp[5001];
int size;
long long f(int n)
{
	if (size <= n)return 1;
	if (ddp[n] != -1)return ddp[n];
	if (dp[n] == '0')return 0;
	int result;
	result = f(n + 1); //한 자리의 수
	if (n + 1 < size) { //두 자리의 수
		int k = (dp[n] - '0') * 10 + (dp[n + 1] - '0');
		if (k < 27) result += f(n + 2);
	}
	ddp[n] = result % 1000000;
	return result % 1000000;
}
int main(void)
{
	memset(ddp, -1, sizeof(ddp));
	scanf("%s", dp);
	if (dp[0] == '0') {
		printf("0");
		return 0;
	}
	size = strlen(dp);
	printf("%lld", f(0));
}