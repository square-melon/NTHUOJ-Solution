#include <stdio.h>

int line[9], con[9]; // In con, queen = 1, rook = 0
int queen, rook, ans = 0, usedq, usedr;

int valid(int);
void sol(int);

int main() {
    while (~scanf("%d %d", &queen, &rook)) {
        usedq = 0;
        usedr = 0;
        ans = 0;
        sol(0);
        printf("%d\n", ans);
    }
}

int valid(int n) {
    for (int i = 0; i <= n - 1; i++) {
        if (con[i] || con[n]) {
            if (line[i] == line[n] ||
                line[i] + (n - i) == line[n] ||
                line[i] - (n - i) == line[n]) return 0;
        }else {
            if (line[i] == line[n]) return 0;
        }
    }
    return 1;
}

void sol(int n) {
    if (n == queen + rook) {
        ans++;
        return;
    }else {
        for (int i = 0; i < queen + rook; i++) {
            if (usedq != queen) {
                usedq++;
                line[n] = i;
                con[n] = 1;
                if (valid(n)) sol(n + 1);
                usedq--;
            }
            if (usedr != rook) {
                usedr++;
                line[n] = i;
                con[n] = 0;
                if (valid(n)) sol(n + 1);
                usedr--;
            }
        }
    }
}