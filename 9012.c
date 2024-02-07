#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N;
    char vps[51];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int ans = 0;
        scanf("%s", vps);
        for (int j = 0; j < strlen(vps); j++) {
            if ('(' == vps[j])
                ans++;
            else if (')' == vps[j])
                ans--;
            if (ans < 0)
                break;
        }
        if (ans == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}