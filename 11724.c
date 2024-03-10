#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grf[1001][1001];
int visit[1001];
int N, M;
void dfs(int x)
{
	visit[x] = 1;
	for (int i = 1; i <= N; i++)
		if (grf[x][i] == 1 && !visit[i])
			dfs(i);
}
int main(void)
{
	int ans = 0;
	int a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		grf[a][b] = 1;
		grf[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}
	printf("%d", ans);
}