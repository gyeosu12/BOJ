#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[101];
	while (gets(str) != '\0')
	{
		int under = 0, upper = 0, number = 0, space = 0;
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] >= 'a' && str[j] <= 'z')
				under++;
			else if (str[j] >= 'A' && str[j] <= 'Z')
				upper++;
			else if (str[j] >= '0' && str[j] <= '9')
				number++;
			else if (str[j] == ' ')
				space++;
		}
		printf("%d %d %d %d\n", under, upper, number, space);
	}
}