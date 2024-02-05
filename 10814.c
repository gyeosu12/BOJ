#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int X;
	char Y[101];
}Coord;
int compare(const void* a, const void* b)
{
	Coord pa = *(Coord*)a;
	Coord pb = *(Coord*)b;
	if (pa.X > pb.X) {
		return 1;
	}
	else if (pa.X == pb.X) {
		return 0;
	}
	return -1;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	Coord cor[100000];
	for (int i = 0; i < N; i++)
		scanf("%d %s", &cor[i].X, &cor[i].Y);
	qsort(cor, N, sizeof(Coord), compare);
	for (int i = 0; i < N; i++)
		printf("%d %s\n", cor[i].X, cor[i].Y);
}