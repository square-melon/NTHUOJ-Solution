#include <iostream>
#define ll long long

using namespace std;

ll mod;

ll ppow(ll x, ll y) {
    if (y == 1) return x;
    else if (y == 0) return 1 % mod;
    ll p = ppow(x, y / 2);
    p = p * p % mod;
    return y % 2 ? p * x % mod : p;
}

int main() {
    ll x, y;
    cin >> x >> y >> mod;
    x %= mod;
    cout << ppow(x, y) << '\n';
}