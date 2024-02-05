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
			/*`A->name - B->name`�� �� "���ڿ�"�� �ƴ� �� char�� �迭 ù ��° ������ "�ּ�"(������)��
���ϰ� �˴ϴ�.string.h ��� ���Ͽ� �ִ� strcmp �Լ��� �̿��Ͻø� ���ϴ� ����� ������ �� �ֽ��ϴ�.*/
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