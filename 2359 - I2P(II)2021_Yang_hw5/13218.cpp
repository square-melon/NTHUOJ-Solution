#include <iostream>
#include <set>

using namespace std;

long long yCoord[100005];

int main() {
    auto cmp = [](const auto a, const auto b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    };
    set<pair<long long, long long>, decltype(cmp)> points(cmp);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        points.insert(make_pair(i, 0));
        yCoord[i] = 0;
    }
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long p, u;
            cin >> p >> u;
            points.erase(make_pair(p, yCoord[p]));
            yCoord[p] += u;
            points.insert(make_pair(p, yCoord[p]));
        } else {
            long long x, y, v;
            cin >> x >> y >> v;
            auto lowerboundPair = points.lower_bound(make_pair(x, y));
            if (lowerboundPair != points.end() && (*lowerboundPair).first <= x + v && lowerboundPair->second == y) {
                yCoord[lowerboundPair->first] -= lowerboundPair->first - x;
                points.erase(lowerboundPair);
                points.insert(make_pair(lowerboundPair->first, lowerboundPair->second - (lowerboundPair->first - x)));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i != 1)
            cout << " ";
        cout << yCoord[i];
    }
    cout << "\n";
}