#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int getKeyValue(vector<int> v);
vector<int> readVector();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto cmp = [](const auto &a, const auto &b) { 
        int keya = getKeyValue(a), keyb = getKeyValue(b);
        return keya < keyb;
    };
    set<vector<int>, decltype(cmp)> S(cmp);
    string op;
    while (cin >> op) {
        if (op == "output") {
            for (auto it : S) {
                for (auto el : it)
                    cout << el << " ";
                cout << "\n";
            }
        } else if (op == "insert") {
            int buf;
            vector<int> toinsert = readVector();
            for (auto it : S) {
                if (getKeyValue(toinsert) == getKeyValue(it)) {
                    cout << "exist\n";
                    S.erase(it);
                    reverse(toinsert.begin(), toinsert.end());
                    break;
                }
            }
            S.insert(toinsert);
        } else if (op == "range_out") {
            int start = getKeyValue(readVector());
            int finish = getKeyValue(readVector());
            for (auto it : S) {
                if (getKeyValue(it) >= start && getKeyValue(it) <= finish) {
                    for (auto el : it)
                        cout << el << " ";
                    cout << "\n";
                }
            }
        }
    }
    
}

int getKeyValue(vector<int> v) {
    int res = 0;
    for (unsigned int i = 0; i < v.size(); i++)
        res += v[i] * (v.size() - i);
    return res;
}

vector<int> readVector() {
    int buf;
    vector<int> res;
    cin >> buf;
    while (buf != 0) {
        res.push_back(buf);
        cin >> buf;
    }
    return res;
}