#include <stdio.h>

int parent[1000001];

int find_root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_root(parent[x]);
}
void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x != y)
        parent[y] = x;
}

int main(void)
{
    int n, m, k, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &k, &a, &b);
        if (k == 0) {
            union_root(a, b);
        }
        else if (k == 1) {
            if (find_root(a) == find_root(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}