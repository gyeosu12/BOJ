#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    long int x, y;
    int d, n, s;
    for (int i = 0; i < t; i++) {
        scanf("%ld %ld", &x, &y);
        d = y - x;
        s = (int)sqrt(d);

        if (d == s * s)
            n = 2 * s - 1;
        else if (s * s < d && d <= s * s + s)
            n = 2 * s;
        else
            n = s * 2 + 1;
        printf("%d\n", n);
    }
}