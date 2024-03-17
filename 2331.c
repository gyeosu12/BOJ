#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int visit[300000] = { 0, };
int P;
void dfs(int a)
{
    if (visit[a] == 2)return;

    visit[a] += 1;
    int temp = 0;
    while (a)
    {
        temp += (int)pow((a % 10), P);
        a = a / 10;
    }
    dfs(temp);
}
int main(void)
{
    int A;
    scanf("%d %d", &A, &P);
    dfs(A);
    int ans = 0;
    for (int i = 0; i < 300001; i++)
        if (visit[i] == 1)
            ans++;
    printf("%d\n", ans);
}