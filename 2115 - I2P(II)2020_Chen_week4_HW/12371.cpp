#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str, substr;
    while (cin >> str >> substr) {
        int prefixSum[1001] = {0};
        int str_len = str.size(), substr_len = substr.size();
        for (int i = 1; i <= str_len; i++) {
            prefixSum[i] = prefixSum[i-1];
            if (i > str_len - substr_len + 1) continue;
            bool flag = true;
            for (int j = 0; j < substr_len; j++) {
                if (str[i+j-1] != substr[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) prefixSum[i]++;
        }
        int T, submax = 0;
        cin >> T;
        while (T--) {
            int s, e;
            cin >> s >> e;
            if (e - s + 1 < substr_len) continue;
            else submax = max(submax, prefixSum[e-substr_len+1] - prefixSum[s-1]);
        }
        cout << submax << '\n';
    }
}