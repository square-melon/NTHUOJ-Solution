#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    set<pair<int, int>> com1;
    auto cmp = [](const auto& a, const auto& b) { return a.second == b.second ? a.first < b.first : a.second > b.second; };
    set<pair<int, int>, decltype(cmp)> com2(cmp);
    map<pair<int, int>, int> amount;
    int N, Q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        if (com1.find(make_pair(w, p)) != com1.end())
            amount[make_pair(w, p)]++;
        else
            amount[make_pair(w, p)] = 1;
        com1.insert(make_pair(w, p));
        com2.insert(make_pair(w, p));
    }
    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int w, p;
            cin >> w >> p;
            if (com1.find(make_pair(w, p)) != com1.end())
                amount[make_pair(w, p)]++;
            else
                amount[make_pair(w, p)] = 1;
            com1.insert(make_pair(w, p));
            com2.insert(make_pair(w, p));
        } else if (op == 2) {
            int w, p;
            cin >> w >> p;
            if (com1.find(make_pair(w, p)) != com1.end()) {
                cout << "OK\n";
                if (amount[make_pair(w, p)] != 1)
                    amount[make_pair(w, p)]--;
                else {
                    amount.erase(make_pair(w, p));
                    com1.erase(make_pair(w, p));
                    com2.erase(make_pair(w, p));
                }
            } else 
                cout << "No Item\n";
        } else if (op == 3) {
            int w;
            cin >> w;
            auto found = com1.lower_bound(make_pair(w, 0));
            if (found == com1.end())
                cout << "No Item\n";
            else {
                cout << "OK " << found->first << " " << found->second << "\n";
                if (amount[make_pair(found->first, found->second)] != 1)
                    amount[make_pair(found->first, found->second)]--;
                else {
                    amount.erase(make_pair(found->first, found->second));
                    com2.erase(make_pair(found->first, found->second));
                    com1.erase(make_pair(found->first, found->second));
                }
            }
        } else if (op == 4) {
            int p;
            cin >> p;
            auto found = com2.lower_bound(make_pair(0, p));
            if (found == com2.end())
                cout << "No Item\n";
            else {
                cout << "OK " << found->first << " " << found->second << "\n";
                if (amount[make_pair(found->first, found->second)] != 1)
                    amount[make_pair(found->first, found->second)]--;
                else {
                    amount.erase(make_pair(found->first, found->second));
                    com1.erase(make_pair(found->first, found->second));
                    com2.erase(make_pair(found->first, found->second));
                }
            }
        }
    }
}