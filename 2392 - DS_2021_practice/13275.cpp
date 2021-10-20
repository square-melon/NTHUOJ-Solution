#include <iostream>

using namespace std;
int sorted[200001];

int binarySearch(int x, int l, int r) {
    int middle = (l + r) / 2;
    if (x == sorted[middle])
        return middle;
    else if (x > sorted[middle])
        return binarySearch(x, middle + 1, r);
    else
        return binarySearch(x, l, middle - 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sorted[i];
    int x;
    while (cin >> x) cout << binarySearch(x, 0, n - 1) << "\n";
}