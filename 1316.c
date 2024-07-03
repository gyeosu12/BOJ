#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);
    while (n--)
    {
        int icout = 1; //이것이 count에 추가될 함수인지?
        char word[101];
        scanf("%s", &word);
        for (int i = 0; i < strlen(word); i++) {
            for (int j = 0; j < (i - 1); j++) {
                if (word[i] == word[j] && word[i] != word[i - 1]) { //중간에 다른 단어가 있음. 즉, 그룹 단어가 아님
                    icout = 0;
                    break;
                }
            }
            if (icout == 0)
                break;
        }
        if (icout == 1)
            count++;
    }
    printf("%d", count);
}