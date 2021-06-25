#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class State {
public:
    State(int* arr) {
        for (int i = 0; i < 8; i++)
            puzzle[i] = arr[i];
        sorted = false;
        move = 0;
    }

    State(const State& s) {
        for (int i = 0; i < 8; i++)
            puzzle[i] = s.puzzle[i];
        sorted = s.sorted;
        move = s.move;
    }

    void Shift() {
        int newArr[8];
        for (int i = 0; i < 8; i++)
            newArr[(i+1)%8] = puzzle[i];
        for (int i = 0; i < 8; i++)
            puzzle[i] = newArr[i];
        move++;
    }

    void swapAdj(int a, int b) {
        swap(puzzle[a], puzzle[b]);
        move++;
    }

    void toSort(int start, int end) {
        for (int i = start; i <= end; i++) {
            for (int j = i + 1; j <= end; j++) {
                if (puzzle[i] > puzzle[j])
                    swap(puzzle[i], puzzle[j]);
            }
        }
        sorted = true;
        move++;
    }

    bool operator== (const State& s) const {
        for (int i = 0; i < 8; i++) {
            if (puzzle[i] != s.puzzle[i])
                return false;
        }
        return true;
    }

    bool operator< (const State& s) const {
        for (int i = 0; i < 8; i++) {
            if (puzzle[i] != s.puzzle[i])
                return puzzle[i] < s.puzzle[i];
        }
        return false;
    }

    int puzzle[8];
    bool sorted;
    int move;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int tmp[8];
        for (int i = 0; i < 8; i++)
            cin >> tmp[i];
        State start(tmp);
        for (int i = 0; i < 8; i++)
            cin >> tmp[i];
        State finish(tmp);
        if (start == finish) {
            cout << "0\n";
            continue;
        }
        queue<State> bfs_queue;
        set<State> visited;
        int ans = -1;
        bfs_queue.push(start);
        while (!bfs_queue.empty()) {
            State nowState = bfs_queue.front();
            bfs_queue.pop();
            if (visited.find(nowState) != visited.end())
                continue;
            visited.insert(nowState);
            State nextState = nowState;
            nextState.Shift();
            if (nextState == finish) {
                ans = nextState.move;
                break;
            }
            bfs_queue.push(nextState);

            for (int i = 0; i < 7; i++) {
                nextState = nowState;
                nextState.swapAdj(i, i + 1);
                if (nextState == finish) {
                    ans = nextState.move;
                    break;
                }
                bfs_queue.push(nextState);
            }
            if (ans != -1)
                break;
            
            if (!nowState.sorted) {
                for (int i = 0; i < 8; i++) {
                    for (int j = i + 1; j < 8; j++) {
                        nextState = nowState;
                        nextState.toSort(i, j);
                        if (nextState == finish) {
                            ans = nextState.move;
                            break;
                        }
                        bfs_queue.push(nextState);
                    }
                    if (ans != -1)
                        break;
                }
                if (ans != -1)
                    break;
            }
            // cout << "bfs_queue: " << bfs_queue.size() << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}