#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[101];
	scanf("%[^\n]s", str);//�������� scanf �Է¹��
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] <= 'z' && str[i] >= 'a')
			printf("%c", ((str[i] - 'a' + 13) % 26) + 'a');
		else if (str[i] <= 'Z' && str[i] >= 'A')
			printf("%c", ((str[i] - 'A' + 13) % 26) + 'A');
		else
			printf("%c", str[i]);
	}
}