#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//사이클인지 판명해야됨 그러므로 visit가 1인경우 done 도 1을해줌 그후 visit=1 done=1일경우 사이클 다 세줌

int visit[100001];
int done[100001];
int arr[100001];
int ans;

void dfs(int a)
{
    visit[a] = 1;
    int next = arr[a];
    if (1 != visit[next])
        dfs(next);
    else if (1 != done[next]) {
        for (int i = next; i != a; i = arr[i])
            ans++;
        ans++;
    }
    done[a] = 1;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {

        int n;
        ans = 0;
        memset(visit, 0, sizeof(visit));
        memset(done, 0, sizeof(done));

        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
            scanf("%d", arr + j);

        for (int j = 1; j <= n; j++) {
            if (1 != visit[j])
                dfs(j);
        }
        printf("%d\n", n - ans);
    }
}