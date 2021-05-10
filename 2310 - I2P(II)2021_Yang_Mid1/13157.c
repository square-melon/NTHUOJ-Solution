#include <stdio.h>

long long p, q, idx;
long long els[100005], coef[100005];
char str[1000005];

int readNum();
long long construct(long long int, long long int, long long int);

int main() {
    scanf("%lld %lld", &p, &q);
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &els[i]);
    scanf("%s", str);
    idx = 0;
    long long ans = construct(p, q, 1);
    scanf("%d", &m);
    while (m--) {
        int e;
        long long v;
        scanf("%d %lld", &e, &v);
        ans += coef[e] * (v - els[e]) % q + q;
        ans %= q;
        els[e] = v;
        printf("%lld\n", ans);
    }
}

int readNum() {
    int n = 0;
    while (str[idx] >= '0' && str[idx] <= '9') {
        n *= 10;
        n += str[idx] - '0';
        idx++;
    }
    return n;
}

long long construct(long long int p, long long int q, long long int nowCoef) {
    if (str[idx] != 'f') {
        int a = readNum();
        coef[a] += nowCoef;
        coef[a] %= q;
        return els[a] * nowCoef % q;
    } else {
        idx += 2;
        long long lv = construct(p, q, nowCoef * p % q);
        idx++;
        long long rv = construct(p, q, nowCoef);
        idx++;
        return (lv + rv) % q;
    }
}