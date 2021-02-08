#include <stdio.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int main() {
    int n, ma = 0, mi = 1e9, x;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &x);
        ma = max(x, ma);
        mi = min(x, mi);
    }
    printf("%d\n", 2 * (ma - mi));
}