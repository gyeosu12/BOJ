#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;
typedef struct Queue {
    node* head;
    node* tail;
    int count;
}Queue;
void init(Queue* q)
{
    q->head = q->tail = NULL;
    q->count = 0;
}
int empty(Queue* q)
{
    return q->count == 0;
}
void push(Queue* q, int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (empty(q))
        q->head = newnode;
    else
        q->tail->next = newnode;
    q->tail = newnode;
    q->count++;
}
int pop(Queue* q)
{
    int data;
    node* nod;
    if (empty(q))
        return 0;
    nod = q->head;
    data = nod->data;
    q->head = nod->next;
    free(nod);
    q->count--;
    return data;
}

int main(void)
{
    node q;
    init(&q);
    int N, a;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        push(&q, i);
    for (int i = 0; i < N - 1; i++) {
        pop(&q);
        a = pop(&q);
        push(&q, a);
    }
    printf("%d\n", pop(&q));
}