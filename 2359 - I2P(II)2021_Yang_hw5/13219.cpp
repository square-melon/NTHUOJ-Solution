#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<pair<int, int>> bfs_queue;
vector<int> dis[100005];
vector<int> grid[100005];
int startx, starty, endx, endy;

void BFS();

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            grid[i].push_back(1);
            dis[i].push_back(0);
        }
    }
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++)
            grid[i][j] = str[j-1] - '0';
    } 
    cin >> startx >> starty >> endx >> endy;
    bfs_queue.push_back(make_pair(startx, starty));
    BFS();
    if (dis[endx][endy] == 0)
        cout << "-1" << '\n';
    else
        cout << dis[endx][endy] << '\n';
}

void BFS() {
    while (!bfs_queue.empty()) {
        int x = bfs_queue.front().first, y = bfs_queue.front().second;
        bfs_queue.pop_front();
        if (x == endx && y == endy)
            return;
        else {
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++) {
                if (grid[x + dx[i]][y + dy[i]] == 0 && (dis[x + dx[i]][y + dy[i]] > dis[x][y] + 1 || dis[x + dx[i]][y + dy[i]] == 0)) {
                    bfs_queue.push_back(make_pair(x + dx[i], y + dy[i]));
                    dis[x + dx[i]][y + dy[i]] = dis[x][y] + 1;
                }
            }
        }
    }
}