#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int data;
    int bul;
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

void makeQ(int X, int Y)
{
    node* d = tail->prev;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = X;
    newnode->bul = Y;
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
int main(void)
{
    int N;
    int ans[1001];
    scanf("%d", &N);
    int idx;
    init();
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        makeQ(i, num);
    }
    idx = head->next->bul;
    pl1();
    ans[0] = 1;
    for (int i = 1; i < N; i++) {
        if (idx > 0) {
            for (int j = 0; j < idx - 1; j++) {
                pl2();
            }
            ans[i] = head->next->data;
            idx = head->next->bul;
            pl1();
        }
        else if (idx < 0) {
            for (int j = 0; j < abs(idx); j++) {
                pl3();
            }
            ans[i] = head->next->data;
            idx = head->next->bul;
            pl1();
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ", ans[i]);
}