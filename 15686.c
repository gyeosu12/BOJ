#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.집과 치킨집을 따로 받는다.
//2.조합으로 시킨집 선택.
//3.최소값으로 거리 출력

typedef struct coord
{
    int X;
    int Y;
}coord;

coord house[2501];
coord bbq[2501];
int N, M, ans = 99999999;
int temp[13];
int housek = 0, bbqk = 0;

//집마다 치킨집 탐색해서 제일 작은거리 넣고 집마다 거리 합치기
void combi(int cnt, int start)
{
    if (cnt == M) {//치킨집 최대 갯수하고 같으면
        int minhouse = 0;
        for (int i = 0; i < housek; i++) {
            int house_bbq = 999999999;
            for (int j = 0; j < M; j++) {
                int tem = abs(house[i].X - bbq[temp[j]].X) + abs(house[i].Y - bbq[temp[j]].Y);
                if (house_bbq > tem)
                    house_bbq = tem;
            }
            minhouse += house_bbq;
        }
        if (minhouse < ans)
            ans = minhouse;
    }
    else {
        for (int i = start; i < bbqk; i++) {
            temp[cnt] = i;
            combi(cnt + 1, i + 1);
        }
    }
}

int main(void)
{
    int k;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &k);
            if (k == 1) {
                house[housek].X = i;
                house[housek].Y = j;
                housek++;
            }
            else if (k == 2) {
                bbq[bbqk].X = i;
                bbq[bbqk].Y = j;
                bbqk++;
            }
        }
    }
    combi(0, 0);
    printf("%d", ans);
}