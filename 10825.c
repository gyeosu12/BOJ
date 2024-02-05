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
	char X[11];
	int Y;
	int Z;
	int H;
}Coord;
int compare(const void* a, const void* b)
{
	Coord pa = *(Coord*)a;
	Coord pb = *(Coord*)b;
	if (pa.Y == pb.Y) {
		if (pa.Z == pb.Z) {
			if (pa.H == pb.H)
				return strcmp(pa.X, pb.X);
			/*`A->name - B->name`은 두 "문자열"이 아닌 두 char형 배열 첫 번째 원소의 "주소"(포인터)를
비교하게 됩니다.string.h 헤더 파일에 있는 strcmp 함수를 이용하시면 원하는 기능을 구현할 수 있습니다.*/
			else
				return pa.H < pb.H;
		}
		else
			return pa.Z > pb.Z;
	}
	else
		return pa.Y < pb.Y;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	Coord cor[100000];
	for (int i = 0; i < N; i++)
		scanf("%s %d %d %d", &cor[i].X, &cor[i].Y, &cor[i].Z, &cor[i].H);
	qsort(cor, N, sizeof(Coord), compare);
	for (int i = 0; i < N; i++)
		printf("%s\n", cor[i].X);
}