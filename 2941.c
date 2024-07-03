#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[101];
    scanf("%s", &word);
    int ans = strlen(word);
    for (int i = 1; i < strlen(word); i++) {
        if (word[i] == '-') {
            if (word[i - 1] == 'c' ||
                word[i - 1] == 'd')
                ans--;
        }
        else if (word[i] == 'j') {
            if (word[i - 1] == 'l' ||
                word[i - 1] == 'n')
                ans--;
        }
        else if (word[i] == '=') {
            if (word[i - 1] == 'c' ||
                word[i - 1] == 'z' ||
                word[i - 1] == 's') {
                ans--;
                if (word[i - 2] == 'd' && word[i - 1] == 'z')
                    ans--;
            }
        }
    }
    printf("%d", ans);
}
