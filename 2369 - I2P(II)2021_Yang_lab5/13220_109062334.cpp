#include <iostream>
#include <set>

using namespace std;

long long int yCoord[100005];
bool isVanished[100005];

int main() {
    auto cmp = [](const auto a, const auto b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    };
    set<pair<long long, long long>, decltype(cmp)> points(cmp);
    int N, Q;
    cin >> N >> Q;
    for (long long int i = 1; i <= N; i++) {
        points.insert(make_pair(i, 0));
        yCoord[i] = 0;
        isVanished[i] = false;
    }
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long int p, u;
            cin >> p >> u;
            if (isVanished[p] == true)
                continue;
            auto tmp = yCoord[p];
            points.erase(make_pair(p, yCoord[p]));
            yCoord[p] += u;
            points.insert(make_pair(p, yCoord[p]));
        } else {
            long long int x, y, v;
            cin >> x >> y >> v;
            auto lowerboundPair = points.lower_bound(make_pair(x, y));
            if (lowerboundPair != points.end() && y == lowerboundPair->second && x + v >= lowerboundPair->first) {
                isVanished[lowerboundPair->first] = true;
                points.erase(lowerboundPair);
            }
                
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i != 1)
            cout << ' ';
        if (isVanished[i])
            cout << "-1";
        else
            cout << yCoord[i];
    }
    cout << '\n';
}