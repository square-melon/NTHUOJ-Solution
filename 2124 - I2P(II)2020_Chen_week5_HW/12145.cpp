#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c;
    int n, chr[26] = {0};
    bool flag = false;
    cin >> n;
    if (n == 1) flag = true;
    while (n--) {
        cin >> c;
        if (flag) continue;
        if (chr[c - 'a'] == 1) flag = true;
        else chr[c - 'a'] = 1;
    }
    if (flag) cout << "I'm the god of Knuckles!\n";
    else cout << "Different makes perfect\n";
}