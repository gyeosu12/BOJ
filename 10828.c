#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    int N;
    scanf("%d", &N);
    int num = 0;
    int p[10001];
    for (int i = 0; i < N; i++) {
        char c[6];
        scanf("%s", c);
        if (!strcmp(c, "push")) {
            int n;
            scanf("%d", &n);
            p[num] = n;
            num++;
        }
        if (!strcmp(c, "pop")) {
            if (num == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", p[num - 1]);
                p[num - 1] = p[num];
                num--;
            }
        }
        if (!strcmp(c, "size")) {
            printf("%d\n", num);
        }
        if (!strcmp(c, "empty")) {
            if (num == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        if (!strcmp(c, "top")) {
            if (num == 0)
                printf("-1\n");
            else
                printf("%d\n", p[num - 1]);
        }
    }
}