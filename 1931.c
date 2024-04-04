#include <stdio.h>

#include <stdlib.h>

typedef struct {

    int a;

    int b;

}meet;

meet arr[100001];

int compare(const void* x, const void* y)

{

    meet m1 = *(meet*)x;

    meet m2 = *(meet*)y;

    if (m1.b > m2.b)

        return 1;

    else if (m1.b == m2.b) {

        if (m1.a > m2.a)

            return 1;

        else

            return -1;

    }

    else

        return -1;

}

int main(void) {

    int n, ans = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d %d", &arr[i].a, &arr[i].b);

    }

    qsort(arr, n, sizeof(meet), compare);

    int tem = arr[0].b;

    for (int i = 1; i < n; i++) {

        if (tem <= arr[i].a) {

            ans++;

            tem = arr[i].b;

        }

    }

    printf("%d\n", ans);

}