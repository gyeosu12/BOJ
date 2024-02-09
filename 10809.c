#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char S[101];
	int count[123];
	int dp[123];
	scanf("%s", S);
	memset(count, -1, sizeof(count));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < strlen(S); i++) {
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (S[i] == j && dp[j] == -1) {
				count[j] = i;
				dp[j] = 1;
			}
			else
				continue;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%d ", count[i]);
	}
}