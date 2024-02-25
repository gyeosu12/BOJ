#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://gall.dcinside.com/board/view/?id=programming&no=1324370 구조체 관련 오류
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
void push_front(int X)
{
    node* d = head->next;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = X;
    newnode->next = d;
    newnode->prev = head;
    d->prev = newnode;
    head->next = newnode;
}
void push_back(int X)
{
    node* d = tail->prev;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = X;
    newnode->prev = d;
    newnode->next = tail;
    d->next = newnode;
    tail->prev = newnode;
}
int pop_front(void)
{
    if (head->next == tail)
        return -1;
    else {
        node* d = head->next;
        int i = d->data;
        head->next = d->next;
        d->next->prev = head;
        free(d);
        return i;
    }
}
int pop_back(void)
{
    if (head->next == tail)
        return -1;
    else {
        node* d = tail->prev;
        int i = d->data;
        d->prev->next = tail;
        tail->prev = d->prev;
        free(d);
        return i;
    }
}
int size(void)
{
    int i = 0;
    if (head->next != tail) {
        node* d = head;
        while (d->next != tail)
        {
            d = d->next;
            i++;
        }
    }
    return i;
}
int empty(void)
{
    if (head->next == tail)
        return 1;
    else
        return 0;
}
int front(void)
{
    if (head->next == tail)
        return -1;
    else
        return head->next->data;
}
int back(void)
{
    if (head->next == tail)
        return -1;
    else
        return tail->prev->data;
}
int main(void)
{
    init();
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char c[12];
        scanf("%s", c);
        if (!strcmp(c, "push_front")) {
            int n;
            scanf("%d", &n);
            push_front(n);
        }
        if (!strcmp(c, "push_back")) {
            int n;
            scanf("%d", &n);
            push_back(n);
        }
        if (!strcmp(c, "pop_front")) {
            printf("%d\n", pop_front());
        }
        if (!strcmp(c, "pop_back")) {
            printf("%d\n", pop_back());
        }
        if (!strcmp(c, "size")) {
            printf("%d\n", size());
        }
        if (!strcmp(c, "empty")) {
            printf("%d\n", empty());
        }
        if (!strcmp(c, "front")) {
            printf("%d\n", front());
        }
        if (!strcmp(c, "back")) {
            printf("%d\n", back());
        }
    }
}