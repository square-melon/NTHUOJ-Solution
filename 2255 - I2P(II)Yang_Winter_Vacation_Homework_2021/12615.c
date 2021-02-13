#include <stdio.h>

char map[105][105];
char checkstr[11] = "ICPCASIASG";
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, sol;

void dfs(int x, int y, int c) {
    if (c == 10) sol = 1;
    else {
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == checkstr[c]) dfs(nx, ny, c + 1);
        }
    }
}

int main() {
    char str[10005];
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] = str[i*n+j];
    sol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sol == 1) break;
            if (map[i][j] == 'I') dfs(i, j, 1);
        }
        if (sol == 1) break;
    }
    if (sol) printf("YES\n");
    else printf("NO\n");
}