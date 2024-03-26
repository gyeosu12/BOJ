#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visit[101][101];
char RGB[101][101];
int N;
int numX[4] = { 0,0,1,-1 };
int numY[4] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	if (visit[x][y] == 1)
		return;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int X = numX[i] + x;
		int Y = numY[i] + y;
		if (RGB[x][y] == RGB[X][Y] && !visit[X][Y])
			bfs(X, Y);
	}
}
int rgb()
{
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				ans++;
				bfs(i, j);
			}
		}
	}
	return ans;
}

int main(void)
{
	memset(visit, 0, sizeof(visit));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &RGB[i][j]);
		}
	}
	printf("%d ", rgb());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (RGB[i][j] == 'R')
				RGB[i][j] = 'G';
		}
	}
	memset(visit, 0, sizeof(visit));

	printf("%d\n", rgb());
}