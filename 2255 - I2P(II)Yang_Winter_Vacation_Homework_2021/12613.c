// a * b + a + b - a * 10 ^ digit(b) - b = 0
//         a * b + a - a * 10 ^ digit(b) = 0
//                                 b + 1 = 10 ^ digit(b)
// b + 1 must be power of 10

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long A, B;
        scanf("%lld %lld", &A, &B);
        long long k = 10, cal = 0;
        while (k - 1 <= B) {
            cal++;
            k *= 10;
        }
        printf("%lld\n", A * cal);
    }
}