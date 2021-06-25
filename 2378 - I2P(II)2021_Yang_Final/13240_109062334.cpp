#include <iostream>
#include <queue>

using namespace std;
queue<int> people[3], VIP;

int line[3] = {-1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string op;
    while (cin >> op) {
        if (op == "ENQUEUE") {
            int id;
            cin >> id;
            if (id % 5 == 0)
                VIP.push(id);
            else {
                int exist = -1;
                for (int i = 0; i < 3; i++) {
                    if (id % 3 == line[i])
                        break;
                    else if (line[i] == -1) {
                        exist = i;
                        break;
                    }
                }
                people[id%3].push(id);
                if (exist != -1)
                    line[exist] = id % 3;
            }
        } else if (op == "DEQUEUE") {
            bool first = false;
            if (VIP.size() != 0) {
                cout << VIP.front();
                first = true;
                VIP.pop();
            }
            if (line[0] != -1) {
                int res = people[line[0]].front();
                people[line[0]].pop();
                if (people[line[0]].size() == 0) {
                    line[0] = line[1];
                    line[1] = line[2];
                    line[2] = -1;
                }
                if (first)
                    cout << " " << res;
                else
                    cout << res;
            }
            cout << "\n";
        }
    }
    return 0;
}