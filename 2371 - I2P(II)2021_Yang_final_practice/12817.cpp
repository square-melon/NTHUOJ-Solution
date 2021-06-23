#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto cmp = [](const auto &a, const auto &b) {
        int len1 = (a.second - a.first) / 2;
        int len2 = (b.second - b.first) / 2;
        if (len1 != len2)
            return len1 > len2;
        else
            return a.first < b.first;
    };
    set<pair<int, int>, decltype(cmp)> interval(cmp);
    set<int> taken;
    vector<int> where;
    int n, m, s, dis;
    cin >> n >> m >> s;
    dis = n + 1;
    int t = 2 * m;
    taken.insert(0);
    taken.insert(n + 1);
    interval.insert(make_pair(0, n + 1));
    where.resize(m + 1, -1);
    while (t--) {
        string op;
        int student;
        cin >> op >> student;
        if (op == "i") {
            auto best = interval.begin();
            int mid = (best->first + best->second) / 2;
            if (best->first != 0)
                dis = min(dis, mid - best->first);
            if (best->second != n + 1)
                dis = min(dis, best->second - mid);
            where[student] = mid;
            taken.insert(mid);
            interval.insert(make_pair(best->first, mid));
            interval.insert(make_pair(mid, best->second));
            interval.erase(best);
        } else if (op == "o") {
            int mid = where[student];
            auto pos = taken.find(mid);
            auto leftIt = pos;
            leftIt--;
            auto rightIt = pos;
            rightIt++;
            taken.erase(mid);
            interval.erase(make_pair(*leftIt, mid));
            interval.erase(make_pair(mid, *rightIt));
            interval.insert(make_pair(*leftIt, *rightIt));
            where[student] = -1;
        }
    }
    if (dis >= s)
        cout << "YES\n";
    else
        cout << "NO\n";
    if (dis == n + 1)
        cout << "INF\n";
    else
        cout << dis << "\n";
    return 0;
}