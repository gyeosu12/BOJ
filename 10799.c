#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char arr[100001];
    scanf("%s", arr);
    int hi = 0;
    int ans = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] == '(')
            hi++;
        else {
            hi--;
            if (arr[i - 1] == '(')
                ans += hi;
            else
                ans++;
        }
    }
    printf("%d\n", ans);
}