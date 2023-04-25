#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool map[1001][1001];
int cnt[1001][1001][2];//0번째는 안부수고, 1번째는 부수고
int xd[4] = {0, 1, 0, -1};
int yd[4] = {1, 0, -1, 0};
int N, M;
vector<pair<int, int>> ones;

struct locNc {
    int row;
    int col;
    bool crash;
};

int bfs() {
    queue<locNc> q;
    cnt[0][0][0] = 1;
    q.push({0, 0, 0});
    cnt[0][0][0] = true;
    while (!q.empty()) {
        int y = q.front().row;
        int x = q.front().col;
        bool crash = q.front().crash;
        q.pop();
        if (y == N - 1 && x == M - 1)return cnt[y][x][crash];
        for (int i = 0; i < 4; i++) {
            int nY = y + yd[i];
            int nX = x + xd[i];
            if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
            if (map[nY][nX] && cnt[nY][nX][crash]==0) {
                cnt[nY][nX][crash] = cnt[y][x][crash] + 1;
                q.push({nY, nX, crash});
            }
            if (!map[nY][nX] && !crash) {
                cnt[nY][nX][1] = cnt[y][x][crash] + 1;
                q.push({nY, nX, 1});
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string k;
        cin >> k;
        for (int j = 0; j < M; j++)
            map[i][j] = (k[j] == '0');

    }
    cout << bfs();
}

