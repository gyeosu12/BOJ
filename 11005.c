#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(int a, int b) {
    if (a != 0) {
        convert(a / b, b);
        if (a % b > 9 && b > 10)
            printf("%c", 'A' + a % b - 10);
        else
            printf("%d", a % b);
    }
}
int main(void)
{
    int n, b;
    scanf("%d %d", &n, &b);
    convert(n, b);
}