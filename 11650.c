#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int min(int A, int B)
{
    if (A < B)return A;
    else return B;
}
*/
typedef struct
{
    int X;
    int Y;
}Coord;
int compare(const void* a, const void* b)
{
    Coord pa = *(Coord*)a;
    Coord pb = *(Coord*)b;
    if (pa.X > pb.X) {
        return 1;
    }
    else if (pa.X == pb.X) {
        if (pa.Y > pb.Y)
            return 1;
        else
            return -1;
    }
    return -1;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    Coord cor[100000];
    for (int i = 0; i < N; i++)
        scanf("%d %d", &cor[i].X, &cor[i].Y);
    qsort(cor, N, sizeof(Coord), compare);
    for (int i = 0; i < N; i++)
        printf("%d %d\n", cor[i].X, cor[i].Y);
}