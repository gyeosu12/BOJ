#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* head, * tail;
void init()
{
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
}

void makeQ(int X)
{
    node* d = tail->prev;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = X;
    newnode->prev = d;
    newnode->next = tail;
    d->next = newnode;
    tail->prev = newnode;
}
void pl1()
{
    node* d = head->next;
    head->next = d->next;
    d->next->prev = head;
    free(d);
}
void pl2()
{
    node* d = head->next;
    head->next = d->next;
    d->next->prev = head;
    d->next = tail;
    d->prev = tail->prev;
    tail->prev->next = d;
    tail->prev = d;
}
void pl3()
{
    node* d = tail->prev;
    tail->prev = d->prev;
    d->prev->next = tail;
    d->next = head->next;
    d->prev = head;
    head->next->prev = d;
    head->next = d;
}
//맨앞의 숫자가 뽑을 숫자면 1 그외 
int main(void)
{
    init();
    int N, M;
    int ans = 0;
    int num[51];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d", num + i);
    for (int i = 1; i <= N; i++)
        makeQ(i);
    int siz = N;
    for (int i = 0; i < M; i++) {
        int idx = 0;
        if (head->next != tail) { //인덱스 구하기
            node* d = head;
            while (d->next->data != num[i])
            {
                d = d->next;
                idx++;
            }
        }
        if (head->next->data == num[i]) {
            pl1();
            siz--;
        }
        else if (idx <= siz / 2) {
            while (head->next->data != num[i])
            {
                pl2();
                ans++;
            }
            pl1();
            siz--;
        }
        else if (idx > siz / 2) {
            while (head->next->data != num[i])
            {
                pl3();
                ans++;
            }
            pl1();
            siz--;
        }
    }
    printf("%d\n", ans);
}