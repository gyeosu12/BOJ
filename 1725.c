#include <stdio.h>
#include <string.h>
int max(int A, int B)
{
    if (A > B)return A;
    else return B;
}
typedef struct node {
    struct node* next;
    int data;
}node;
node* head;
void init()
{
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
}
void push(int a)
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

int main(void)
{
    init();
    int N, ans = 0;
    int arr[100002] = { 0, };
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr + i);
    }
    push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (head->next != NULL && arr[head->next->data] > arr[i])
        {
            int temp = head->next->data;
            pop();
            ans = max(ans, arr[temp] * (i - 1 - head->next->data));
        }
        push(i);
    }
    printf("%d\n", ans);
}