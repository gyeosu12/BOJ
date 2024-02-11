#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int arr[10001];
	int front = 0;
	int num = 0;
	for (int i = 0; i < N; i++) {
		char c[6];
		scanf("%s", c);
		if (!strcmp(c, "push")) {
			int n;
			scanf("%d", &n);
			arr[num] = n;
			num++;
		}
		if (!strcmp(c, "pop")) {
			if (num - front <= 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", arr[front]);
				front++;
			}
		}
		if (!strcmp(c, "size")) {
			printf("%d\n", num - front);
		}
		if (!strcmp(c, "empty")) {
			if (num - front <= 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if (!strcmp(c, "front")) {
			if (num - front <= 0)
				printf("-1\n");
			else
				printf("%d\n", arr[front]);
		}
		if (!strcmp(c, "back")) {
			if (num - front <= 0)
				printf("-1\n");
			else
				printf("%d\n", arr[num - 1]);
		}
	}
}