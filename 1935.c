#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//double형 사용안하니 틀렸음 범위를 넘어선듯 isupper사용해서 코드길이좀 줄임
typedef struct node {
    struct node* next;
    double data;
}node;
node* head;
void init()
{
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
}
void push(double a)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = head->next;
    head->next = newnode;
    newnode->data = a;
}
double pop()
{
    node* pp = head->next;
    double ppnum = head->next->data;
    head->next = pp->next;
    free(pp);
    return ppnum;
}
double token(double a, double b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
}

int main(void)
{
    init();
    int N, num, j, M[27];
    char arr[101];
    double ans = 0;

    scanf("%d", &N);
    scanf("%s", arr);

    int str = strlen(arr);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        M[i] = num;
    }
    for (int i = 0; i < str; i++) {
        if (isupper(arr[i])) {
            j = arr[i] - 'A';
            push(M[j]);
        }
        else {
            double a, b;
            b = pop();
            a = pop();
            ans = token(a, b, arr[i]);
            push(ans);
        }
    }
    printf("%.2f\n", ans);
}