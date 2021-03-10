#include <stdio.h>
#include <stdlib.h>

int start[100005], end[100005], next[1000005];
char str[1000005];

int main() {
    int n, x, T;
    scanf("%d", &n);
    x = 0;
    for (int i = 0; i < n; i++) {
        int sz;
        scanf(" %d ", &sz);
        start[i] = sz ? x : -1;
        end[i] = sz ? x + sz - 1 : -1;
        for (int j = 0; j < sz; j++) {
            scanf("%c", &str[x]);
            x++;
            next[x-1] = j != sz - 1 ? x : -1;
        }
    }
    scanf("%d", &T);
    while (T--) {
        int m, a, b;
        scanf("%d %d %d", &m, &a, &b);
        a--;
        b--;
        if (m == 1) {
            if (start[a] == -1) continue;
            if (start[b] == -1) end[b] = end[a];
            next[end[a]] = start[b];
            start[b] = start[a];
            start[a] = -1;
            end[a] = -1;
        }else if (m == 2) {
            if (start[a] == -1) continue;
            if (start[b] == -1) start[b] = start[a];
            else next[end[b]] = start[a];
            end[b] = end[a];
            start[a] = -1;
            end[a] = -1;
        }else {
            int tmp = start[a];
            start[a] = start[b];
            start[b] = tmp;
            tmp = end[a];
            end[a] = end[b];
            end[b] = tmp;
        }
    }
    x = 0;
    for (int i = 0; i < n; i++) {
        x = start[i];
        while (x != -1) {
            printf("%c", str[x]);
            x = next[x];
        }
        printf("\n");
    }
}