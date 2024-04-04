#include <stdio.h>

#include <math.h>

int but[10] = { 0, };

int Min(int x, int y) {

    return x < y ? x : y;
}

int ret(int n)

{

    if (n == 0) {

        if (but[0] == 1)

            return 0;

        return 1;

    }

    int rst = 0;

    while (n) {

        if (but[n % 10] == 1)

            return 0;

        n /= 10;

        rst++;

    }

    return rst;

}

int main(void) {

    int n, m, a, k;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {

        scanf("%d", &k);

        but[k] = 1;

    }

    int min = abs(n - 100);

    for (int i = 0; i < 1000001; i++) {

        a = ret(i);

        if (a) {

            min = Min(min, abs(n - i) + a);

        }

    }

    printf("%d\n", min);

}