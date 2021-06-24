#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX_MOVE 80

using namespace std;

const int goalRow[] = {-1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
const int goalCol[] = {-1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};

class State {
public:
    int puzzle[4][4];
    int heuristic; // H
    int curMove; // G
    int prevMove;
    int ex, ey;

    State(int arr[4][4]) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                puzzle[i][j] = arr[i][j];
        curMove = 0;
        prevMove = -1;
        setHeuristic();
    }

    State(const State& s) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                puzzle[i][j] = s.puzzle[i][j];
        ex = s.ex;
        ey = s.ey;
        curMove = s.curMove;
        prevMove = s.prevMove;
        heuristic = s.heuristic;
    }

    void setHeuristic() {
        heuristic = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (puzzle[i][j]) {
                    int goalX = goalRow[puzzle[i][j]];
                    int goalY = goalCol[puzzle[i][j]];
                    heuristic += abs(goalX - i) + abs(goalY - j);
                    if (i == goalX) {
                        for (int k = j; k < 4; k++) {
                            if (puzzle[i][k] && goalRow[puzzle[i][k]] == i && puzzle[i][j] > puzzle[i][k])
                                heuristic += 2;
                        }
                    }
                    if (j == goalY) {
                        for (int k = i; k < 4; k++) {
                            if (puzzle[k][j] && goalCol[puzzle[k][j]] == j && puzzle[i][j] > puzzle[k][j])
                                heuristic += 2;
                        }
                    }
                }
            }
        }
    }

    void update(int direction, int newX, int newY) {
        prevMove = direction;
        swap(puzzle[newX][newY], puzzle[ex][ey]);
        ex = newX;
        ey = newY;
        curMove++;
        setHeuristic();
    }

    bool operator< (const State& s) const {
        return curMove + heuristic > s.curMove + s.heuristic;
    }

};

int main() {
    priority_queue<State> pq;
    int puzzle[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> puzzle[i][j];
    State start(puzzle);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!puzzle[i][j]) {
                start.ex = i;
                start.ey = j;
            }
        }
    }
    pq.push(start);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!pq.empty()) {
        State nowState = pq.top();
        if (nowState.heuristic == 0) {
            cout << nowState.curMove << "\n";
            break;
        }
        pq.pop();
        if (nowState.heuristic + nowState.curMove > MAX_MOVE)
            continue;
        for (int i = 0; i < 4; i++) {
            int newX = nowState.ex + dx[i];
            int newY = nowState.ey + dy[i];
            if (newX < 0 || newX > 3 || newY < 0 || newY > 3)
                continue;
            if (i == (nowState.prevMove ^ 1))
                continue;
            State nextState = nowState;
            nextState.update(i, newX, newY);
            pq.push(nextState);
        }
    }
    if (pq.empty())
        cout << "-1\n";
    return 0;
}