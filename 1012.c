#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dfs 조건문 추가했어야됨

int filed[50][50];
int N, M;
void dfs(int x, int y)
{
	filed[x][y] = 0;

	if (x + 1 < M && filed[x + 1][y] == 1) dfs(x + 1, y);
	if (y + 1 < N && filed[x][y + 1] == 1) dfs(x, y + 1);
	if (x - 1 >= 0 && filed[x - 1][y] == 1) dfs(x - 1, y);
	if (y - 1 >= 0 && filed[x][y - 1] == 1) dfs(x, y - 1);
}
int main(void)
{
	int T, K;
	int x, y, ans;
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		memset(filed, 0, sizeof(filed));
		scanf("%d %d %d", &M, &N, &K);

		while (K--) {
			scanf("%d %d", &x, &y);
			filed[x][y] = 1;
		}
		ans = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (filed[i][j] == 1) {
					ans++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
}