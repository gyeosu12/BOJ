#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://3catpapa.tistory.com/83 참고 구조체 배열 만들기
//nullptr오류 안내기 위해서 top empty 함수 만듬

typedef struct node {
    struct node* next;
    int data;
}node;

node head[7]; //구조체 배열

void init(node* head)
{
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
}
void push(int a, node* head)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = head->next;
    head->next = newnode;
    newnode->data = a;
}
void pop(node* head)
{
    node* pp = head->next;
    head->next = pp->next;
    free(pp);
}
int top(node* head)
{
    return head->next->data;
}
int empty(node* head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}

int main(void)
{
    for (int i = 1; i < 7; i++)
        init(&head[i]);
    node* p = head;
    int N, P, ans = 0;
    scanf("%d %d", &N, &P);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        while (!empty(p + a) && top(p + a) > b) {
            pop(p + a);
            ans++;
        }
        if (empty(p + a) || top(p + a) < b) {
            push(b, p + a);
            ans++;
        }
    }
    printf("%d\n", ans);
}