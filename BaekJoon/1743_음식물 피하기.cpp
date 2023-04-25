#include <iostream>

using namespace std;

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};
bool map[102][102];
bool visited[102][102];
int m, n, k;
int ans, cnt;

void input() {
    cin >> n >> m >> k;
    while (k--) {
        int x, y;
        cin >> y >> x;
        map[y][x] = true;
    }
}

void dfs(int a, int b) {
    visited[a][b] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int next_y = a + dirY[i];
        int next_x = b + dirX[i];
        if (visited[next_y][next_x] || !map[next_y][next_x])continue;
        if (next_x >= 1 && next_x <= 100 && next_y >= 1 && next_y <= 100)
            dfs(next_y, next_x);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    input();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && map[i][j]) {
                dfs(i, j);
                ans = (cnt > ans ? cnt : ans);
                cnt = 0;
            }
        }
    }
    cout << ans;
    return 0;
}