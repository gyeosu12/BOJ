#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    for (int k = 0; k < N; k++) {
        int t;
        long long int ans = 0;
        scanf("%d", &t);
        int n[101];
        for (int i = 0; i < t; i++)
            scanf("%d", n + i);
        for (int i = 0; i < t - 1; i++) {
            for (int j = i + 1; j < t; j++) {

                ans += bcd(n[i], n[j]);
            }
        }
        printf("%lld\n", ans);
    }
}