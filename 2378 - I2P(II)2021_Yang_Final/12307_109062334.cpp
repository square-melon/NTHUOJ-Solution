#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
map<char, int> words[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;
    set<map<char, int>> exist;
    set<map<char, int>> finding;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            char ch = v[i][j];
            if (ch >= 'A' && ch <= 'Z')
                ch += 'a' - 'A';
            if (words[i].find(ch) != words[i].end())
                words[i][ch]++;
            else
                words[i][ch] = 1;
        }
        if (exist.find(words[i]) == exist.end()) {
            if (finding.find(words[i]) != finding.end()) {
                exist.insert(words[i]);
                finding.erase(words[i]);
            } else
                finding.insert(words[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (exist.find(words[i]) == exist.end())
            cout << v[i] << "\n";
    }
}