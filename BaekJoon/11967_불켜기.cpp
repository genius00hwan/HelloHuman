//
// Created by 김수환 on 2022/11/01.
//
#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int light[101][101];
bool visited[101][101];
int n, m;
int ans;
int yd[] = {1, 0, -1, 0};
int xd[] = {0, 1, 0, -1};
vector<pair<int, int>> btn[101][101];

void bfs() {
    queue<pair<int, int>> q;
    visited[1][1] = true;
    light[1][1] = 1;
    q.push({1, 1});
    ans++;
    bool revisit ;

    while (!q.empty()) {
        revisit = false;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (light[x][y] != 2) {
            for (auto b: btn[x][y]) {
                if (light[b.first][b.second])continue;
                light[b.first][b.second] = true;
                ans++;
                revisit = true;
            }
            light[x][y] = 2;
        }

        if (revisit) {
            for(int i=0;i<101;i++){
                for(int j=0;j<101;j++){
                    visited[i][j] = false;
                }
            }
            visited[x][y] = true;
            while (!q.empty()) q.pop();
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + xd[i];
            int ny = y + yd[i];
            if (visited[nx][ny] || light[nx][ny] == 0)continue;
            if (0 < nx && nx <= n && 0 < ny && ny <= n) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int ax, ay, bx, by;
        cin >> ax >> ay;
        cin >> bx >> by;
        btn[ax][ay].emplace_back(bx,by);
    }
    bfs();
    cout << ans <<endl;

    return 0;
}