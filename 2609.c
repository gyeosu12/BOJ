#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c;
    int d = a * b;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d\n%d\n", a, d / a);
}