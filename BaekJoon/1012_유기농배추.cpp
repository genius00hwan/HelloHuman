#include <iostream>

using namespace std;

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

bool map[52][52];
bool visited[52][52];
int t;
int m, n, k;

void input() {
    cin >> m >> n >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        map[x][y] = true;
    }
}

void dfs(int a, int b) {
    visited[a][b] = true;
    for (int i = 0; i < 4; i++) {
        int next_x = a + dirX[i];
        int next_y = b + dirY[i];
        if (visited[next_x][next_y] || !map[next_x][next_y])continue;
        if (next_x >= 0 && next_x < 50 && next_y >= 0 && next_y < 50)
            dfs(next_x, next_y);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        int ans = 0;
        input();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && map[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                visited[i][j] = false;
                map[i][j] = false;
            }
        }
    }
    return 0;
}