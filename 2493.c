#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[500002];
int ans[500002];

int main(void)
{
    int n;
    int stack = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {

        scanf("%d", arr + i);
        if (stack < arr[i]) {
            ans[i] = 0;
            stack = arr[i];
        }
        else {
            for (int j = i - 1; j >= 1;) {
                if (arr[j] >= arr[i]) {
                    ans[i] = j;
                    break;
                }
                else
                    j = ans[j]; //이 문장이 시간단축의 핵심
                //제일 높은 것보다 이전보다 높은 숫자면 넣기
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}