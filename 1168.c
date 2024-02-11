#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int arr[5001];
    memset(arr, 0, sizeof(arr));
    int N, K;
    int j = 1;
    scanf("%d %d", &N, &K);
    printf("<");
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        while (1)
        {
            if (arr[j] == 0)
                cnt++;
            if (cnt == K) {
                arr[j] = -1;
                if (N - 1 == i)
                    printf("%d>", j);
                else
                    printf("%d, ", j);
                break;
            }
            j++;
            if (j > N)
                j = 1;
        }
    }
}