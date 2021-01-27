#include <stdio.h>
#define ll long long
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

char s[4] = "OuQ";
ll len[51];

void sol(int, ll, ll);

int main() {
    len[1] = 3;
    for (int i = 2; i <= 50; i++) len[i] = 2 * len[i-1] + 3;
    ll l, r;
    int k;
    while (~scanf("%d %lld %lld", &k, &l, &r)) {
        sol(k, l ,r);
        printf("\n");
    }
}

void sol(int k, ll l, ll r) {
    ll l2, r2;
    if (k == 1) for (int i = l; i <= r; i++) printf("%c", s[i]);
    else {
        if (l == 0) printf("O");
        l2 = l - 1, r2 = r - 1;
        if (l2 <= len[k-1] - 1 && r2 >= 0) sol(k - 1, max(0, l2), min(r2, len[k-1] - 1));
        l2 -= len[k-1], r2 -= len[k-1];
        if (l2 <= 0 && r2 >= 0) printf("u");
        l2--, r2--;
        if (l2 <= len[k-1] - 1 && r2 >= 0) sol(k - 1, max(0, l2), min(r2, len[k-1] - 1));
        l2 -= len[k-1], r2 -= len[k-1];
        if (l2 <= 0 && r2 == 0) printf("Q");
    }
}