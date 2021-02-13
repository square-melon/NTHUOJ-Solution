#include <stdio.h>
#define min(a, b) a < b ? a : b

int main() {
    int n, m;
    int a[1000], b[1000], x = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) if (x < m && b[x] >= a[i]) x++;
    printf("%d\n", x);
}