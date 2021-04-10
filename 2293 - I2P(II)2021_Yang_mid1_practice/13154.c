#include <stdio.h>
#include <string.h>

char str[5000005];
long long p, q, idx;

long long cal();

int main() {
    scanf("%lld %lld", &p, &q);
    scanf("%s", str);
    idx = 0;
    printf("%lld\n", cal());
}

long long cal() {
    long long x, y;
    if (str[idx] == 'f') {
        idx += 2;
        x = cal();
        idx++;
        y = cal();
        idx++;
        return (p * x % q + y) % q;
    }else {
        long long num = 0;
        while (str[idx] != ',' && str[idx] != ')') {
            num *= 10;
            num += str[idx] - '0';
            idx++;
        }
        return num;
    }
}