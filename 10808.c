#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char S[101];
	int count[123] = { 0, };
	scanf("%s", S);
	for (int i = 0; i < strlen(S); i++) {
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (S[i] == j)
				count[j]++;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%d ", count[i]);
	}
}