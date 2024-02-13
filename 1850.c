#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//최대 공약수 만큼 1이 반복되어있는 규칙이있음
int main(void)
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	if (b > a) {
		long long int t = a;
		a = b;
		b = t;
	}
	long long int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	for (int i = 0; i < a; i++)
		printf("1");
}