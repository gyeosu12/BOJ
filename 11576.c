#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int Ato10(int A, int m, int* n)
{
    int ans = 0;

    for (int i = 0; i < m; i++)
        ans += n[m - 1 - i] * pow(A, i);

    return ans;
}
void BB(int C, int B)
{
    if (C != 0) {
        BB(C / B, B);
        printf("%d ", C % B);
    }
}
int main(void)
{
    int A, B, C, m;
    int n[25];
    scanf("%d %d", &A, &B);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", n + i);
    C = Ato10(A, m, n);
    BB(C, B);
}