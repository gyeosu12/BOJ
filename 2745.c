#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int b;
    char n[10000];
    scanf("%s %d", n, &b);
    int a = strlen(n);
    long long int sum = 0;
    for (int i = 0; i < a; i++) {
        if (n[a - 1 - i] >= 'A')
            sum += pow(b, i) * ((int)n[a - 1 - i] + 10 - 'A');
        else
            sum += pow(b, i) * ((int)n[a - 1 - i] - '0');
    }
    printf("%lld\n", sum);
}