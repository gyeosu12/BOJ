#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int f(long long int num, long long int n)
{
    long long int ans = 0;
    for (long long int i = 1; i <= num; i *= n)
    {
        ans += (num / i);
    }
    return ans;
}
int main(void)
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    long long int x = f(a, 5) - f(a - b, 5) - f(b, 5);
    long long int y = f(a, 2) - f(a - b, 2) - f(b, 2);
    printf("%lld\n", ((x < y) ? x : y));
}