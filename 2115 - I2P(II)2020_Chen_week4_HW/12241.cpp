#include <iostream>
#define ll long long 
#define m (ll)(1e9 + 7)

using namespace std;

ll **F;

ll** multi(ll** A, ll** B) {
    ll **G;
    G = new ll*[2];
    for (int i = 0; i < 2; i++) G[i] = new ll[2];
    G[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    G[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    G[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    G[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) G[i][j] %= m;
    return G;
}

ll** power(ll n) {
    if (n == 1) return F;
    else {
        ll **B = power(n / 2);
        B = multi(B, B);
        return n % 2 ? multi(B, F) : B;
    }
}

ll fib(ll n) {
    ll **G;
    G = power(n);
    return G[1][0];
}

int main() {
    F = new ll*[2];
    for (int i = 0 ; i < 2; i++) F[i] = new ll[2];
    F[0][0] = 1, F[0][1] = 1, F[1][0] = 1, F[1][1] = 0;
    ll n;
    while (cin >> n) cout << fib(n) << '\n';
}