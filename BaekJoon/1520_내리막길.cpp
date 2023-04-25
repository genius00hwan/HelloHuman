#include <iostream>

using namespace std;

int map[502][502];
int dp[502][502];
bool visited[502][502];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int m, n;

void init() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
}

int dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) return 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 > nx || nx >= m || 0 > ny || ny >= n) continue;
        if (map[nx][ny] < map[x][y])
            dp[x][y] += (visited[nx][ny] ? dp[nx][ny] : dfs(nx, ny));
    }
    return dp[x][y];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    init();
    cout<<dfs(0, 0);
}