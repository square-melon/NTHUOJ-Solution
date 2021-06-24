#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

/*
0 1 2
7   3
6 5 4
*/

class State {
public:
    int tile[8];
    State(int *arr, int st) {
        step = st;
        for (int i = 0; i < 8; i++)
            tile[i] = arr[i];
    };

    bool operator== (const State &s) const {
        for (int i = 0; i < 8; i++) {
            if (tile[i] != s.tile[i])
                return false;
        }
        return true;
    };

    bool operator < (const State &s) const {
        for (int i = 0; i < 8; i++) {
            if (tile[i] != s.tile[i])
                return tile[i] < s.tile[i];
        }
        return false;
	}

    int step;
};

void printState(State s) {
    cout << s.tile[0] << ' ' << s.tile[1] << ' ' << s.tile[2] << '\n';
    cout << s.tile[7] << "   " << s.tile[3] << '\n';
    cout << s.tile[6] << ' ' << s.tile[5] << ' ' << s.tile[4] << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int tmp[8];
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        cin >> tmp[7] >> tmp[3];
        cin >> tmp[6] >> tmp[5] >> tmp[4];
        State start(tmp, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        cin >> tmp[7] >> tmp[3];
        cin >> tmp[6] >> tmp[5] >> tmp[4];
        State end(tmp, 0);

        if (start == end) {
            cout << "0\n";
            continue;
        }

        int ans = -1;
        set<State> visited;
        queue<State> bfs_queue;

        bfs_queue.push(start);

        while (!bfs_queue.empty()) {

            State nowState = bfs_queue.front();
            bfs_queue.pop();
            if (visited.find(nowState) != visited.end())
                continue;
            visited.insert(nowState);
            int newArr[8];
            for (int i = 0; i < 8; i++)
                newArr[(i+1)%8] = nowState.tile[i];
            if (State(newArr, nowState.step + 1) == end) {
                ans = nowState.step + 1;
                break;
            }
            bfs_queue.push(State(newArr, nowState.step + 1));

            for (int i = 0; i < 8; i++)
                newArr[i] = nowState.tile[i];
            for (int i = 0; i < 8; i++) {
                swap(newArr[i], newArr[(i+1)%8]);
                if (State(newArr, nowState.step + 1) == end) {
                    ans = nowState.step + 1;
                    break;
                }
                bfs_queue.push(State(newArr, nowState.step + 1));
                swap(newArr[i], newArr[(i+1)%8]);
            }
            if (ans != -1)
                break;
            for (int i = 7; i >= 4; i--) {
                swap(newArr[i], newArr[i-4]);
                if (State(newArr, nowState.step + 1) == end) {
                    ans = nowState.step + 1;
                    break;
                }
                bfs_queue.push(State(newArr, nowState.step + 1));
                swap(newArr[i], newArr[i-4]);
            }
            if (ans != -1)
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}