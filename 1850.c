#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ִ� ����� ��ŭ 1�� �ݺ��Ǿ��ִ� ��Ģ������
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