#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int d = a * b;
		while (b)
		{
			int c = a % b;
			a = b;
			b = c;
		}
		printf("%d\n", d / a);
	}
}