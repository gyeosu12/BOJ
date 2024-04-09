#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int house[25][25];
int visit[25][25];
int ans[626] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;

int bfs(int x, int y)
{
    int rul = 0;
    if (x < 0 || y < 0 || x >= n || y >= n || visit[x][y] == 1 || house[x][y] == 0)
        return 0;
    visit[x][y] = 1;
    rul++;
    for (int i = 0; i < 4; i++) {
        rul += bfs(x + dx[i], y + dy[i]);
    }
    return rul;
}

int compare(const int* a, const int* b) {
    return(*a - *b);
}

int main(void)
{
    int k = 0;
    scanf("%d", &n);
    memset(visit, 0, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &house[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (house[i][j] == 1 && visit[i][j] == 0) {
                ans[k] = bfs(i, j);
                k++;
            }
        }
    }
    qsort(ans, k, sizeof(int), compare);
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
        printf("%d\n", ans[i]);
}