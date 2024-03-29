#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int room[50][50];
int visited[50][50];
int X[4] = { -1,0,1,0 };
int Y[4] = { 0,1,0,-1 };

int main(void)
{
    int N, M;
    int x, y, ans = 0;//현재 위치
    int dir;

    memset(visited, 0, sizeof(visited));
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &x, &y, &dir);
    dir += 40000000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &room[i][j]);
            if (room[i][j] == 1)
                visited[i][j] = 1;
        }
    }
    while (1) {
        if (!visited[x][y]) {
            visited[x][y] = 1;
            ans++;
        }
        if (!visited[x + 1][y] || !visited[x - 1][y] || !visited[x][y + 1] || !visited[x][y - 1]) {
            dir--;
            if (!visited[x + X[dir % 4]][y + Y[dir % 4]]) {
                x = x + X[dir % 4];
                y = y + Y[dir % 4];
            }
        }
        else {
            if (room[x + X[(dir + 2) % 4]][y + Y[(dir + 2) % 4]] != 1) {
                x = x + X[(dir + 2) % 4];
                y = y + Y[(dir + 2) % 4];
            }
            else if (room[x + X[(dir + 2) % 4]][y + Y[(dir + 2) % 4]] == 1)
                break;
        }
    }
    printf("%d\n", ans);
}