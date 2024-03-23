#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int A[1000001];
int ans[1000001];
int stack[1000001] = { 0, };
int s = -1;

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", A + i);
    for (int i = N - 1; i >= 0; i--) {
        while (s != -1 && stack[s] <= A[i]) {
            s--;
        }
        if (s == -1) {
            s++;
            ans[i] = -1;
        }
        else {
            ans[i] = stack[s];
            s++;
        }
        stack[s] = A[i];
    }
    for (int i = 0; i < N; i++)
        printf("%d ", ans[i]);
}