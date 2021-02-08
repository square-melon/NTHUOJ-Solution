#include <stdio.h>
#include <string.h>

int main() {
    char s[10005];
    int m, l, r, k;
    scanf("%s", s);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &l, &r, &k);
        int k1 = k;
        k1 %= r - l + 1;
        if (k1 == 0) continue;
        int k2 = r - l + 1 - k1;
        char buf[10005];
        int cur = 0;
        for (int i = l + k2 - 1; i < r; i++, cur++) buf[cur] = s[i];
        for (int i = r - 1; i >= r - k2; i--) s[i] = s[i-k1];
        for (int i = l - 1, j = 0; j < cur; i++, j++) s[i] = buf[j];
    }
    printf("%s\n", s);
}