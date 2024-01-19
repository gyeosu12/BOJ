#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*마시기 or 안마시기 마실경우 stack +1 if stack==2 경우 한잔 넘기기*/
int n[10001];
int dp[10001][3];
int N;
int max(int A, int B) 
{ 
	if (A > B)return A; 
	else return B; 
}
int f(int num, int s)
{
    if (num >= N)
        return 0;

    int result = n[num];
    if (dp[num][s] != -1)
        return dp[num][s];

    if (s == 0) {
        int a = f(num + 1, 1) + n[num]; //더하기
        int b = f(num + 1, 0); //그냥 넘기기
        result = max(a, b);
        dp[num][s] = result;
        return result;
    }
    else if (s == 1) {
        int a = f(num + 1, 2) + n[num];
        int b = f(num + 1, 0);
        result = max(a, b);
        dp[num][s] = result;
        return result;
    }
    else { //2일경우
        result = f(num + 1, 0);
        dp[num][s] = result;
        return result;
    }
}
int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", n+i);
	printf("%d", f(0,0));
}