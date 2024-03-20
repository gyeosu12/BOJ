#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, ans = 0;
int dp[25];

int isright(int b)
{
    for (int i = 0; i < b; i++) {
        if (dp[i] == dp[b] || b - i == abs(dp[b] - dp[i]))
            return 0;
    }
    return 1;
}
void queen(int a)
{
    if (a == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        dp[a] = i;
        if (isright(a))
            queen(a + 1);
    }
}

int main(void)
{
    scanf("%d", &n);
    queen(0);
    printf("%d", ans);
}