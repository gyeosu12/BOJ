#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    struct node* next;
    char data;
}node;
node* head;
void init()
{
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
}
void push(char a)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = head->next;
    head->next = newnode;
    newnode->data = a;
}
void pop()
{
    node* pp = head->next;
    head->next = pp->next;
    free(pp);
}
int type_(char C) {
    if (C >= 'A' && C <= 'Z')
        return 1;
    else if (C == '+' || C == '-')
        return 2;
    else if (C == '*' || C == '/')
        return 3;
    else if (C == '(')
        return 4;
    else
        return 5;
}

int main(void)
{
    init();
    char str[102];
    scanf("%s", str);
    int N = strlen(str);
    for (int i = 0; i < N; i++) {

        switch (type_(str[i]))
        {
        case 1:
            printf("%c", str[i]);
            break;
        case 2:
            if (head->next == NULL)
                push(str[i]);
            else if (head->next->data == '(')
                push(str[i]);
            else {
                while (head->next != NULL && head->next->data != '(')
                {
                    printf("%c", head->next->data);
                    pop();
                }
                push(str[i]);
            }
            break;
        case 3:
            if (head->next == NULL)
                push(str[i]);
            else if (head->next->data == '+' || head->next->data == '-' || head->next->data == '(')
                push(str[i]);
            else {
                while (head->next != NULL && head->next->data != '(' &&
                    (head->next->data == '*' || head->next->data == '/'))
                {
                    printf("%c", head->next->data);
                    pop();
                }
                push(str[i]);
            }
            break;
        case 4:
            push(str[i]);
            break;
        case 5:
            while (head->next->data != '(') {
                printf("%c", head->next->data);
                pop();
            }
            pop();
            break;
        }
    }
    while (head->next != NULL) {
        printf("%c", head->next->data);
        pop();
    }
    printf("\n");
}