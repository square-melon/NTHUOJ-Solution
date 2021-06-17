#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct STATE {
    STATE(int lv, int hp, int monsterhp, int steps) : lv(lv), hp(hp), monsterhp(monsterhp), steps(steps) {};
    int lv;
    int hp;
    int monsterhp;
    int steps;
} State;

queue<State> bfs_queue;
bool visited[16][305][405];
int attack[16], heal[16];
int L, HP, MHP, MDMG;
int flag = -1;

void bfs();

int main() {
    cin >> L >> HP >> MHP >> MDMG;
    for (int i = 1; i <= L; i++)
        cin >> attack[i] >> heal[i];
    bfs_queue.push(State(1, HP, MHP, 0));
    bfs();
    if (!bfs_queue.empty())
        cout << bfs_queue.front().steps << "\n";
    else
        cout << "-1\n";
}

void bfs() {
    while (!bfs_queue.empty()) {
        State nowState = bfs_queue.front();
        if (nowState.monsterhp <= 0)
            break;
        if (nowState.hp <= 0) {
            bfs_queue.pop();
            continue;
        }
        if (visited[nowState.lv][nowState.hp][nowState.monsterhp]) {
            bfs_queue.pop();
            continue;
        }
        visited[nowState.lv][nowState.hp][nowState.monsterhp] = true;
        if (nowState.lv != L)
            bfs_queue.push(State(nowState.lv + 1, nowState.hp - MDMG, nowState.monsterhp, nowState.steps + 1));
        if (nowState.hp != HP && heal[nowState.lv] > MDMG)
            bfs_queue.push(State(nowState.lv, min(HP - MDMG, nowState.hp - MDMG + heal[nowState.lv]), nowState.monsterhp, nowState.steps + 1));
        bfs_queue.push(State(nowState.lv, nowState.hp - MDMG, nowState.monsterhp - attack[nowState.lv], nowState.steps + 1));
    }
}