#include <iostream>
#include <queue>

using namespace std;

bool visited[100003];
int n, k, ans;

void bfs() {
    queue<pair<int, int>> q;
    visited[n] = true;
    q.push({n, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == k) {
            ans = cnt;
            break;
        }
        if (cur > 0 && cur < 100001 && !visited[cur - 1]) {
            visited[cur - 1] = true;
            q.push(make_pair(cur - 1, cnt + 1));
        }
        if (cur >= -1 && cur <= 100000 && !visited[cur + 1] ) {
            visited[cur + 1] = true;
            q.push(make_pair(cur + 1, cnt + 1));
        }
        if (cur > 0 && cur <= 50000 && !visited[cur * 2]) {
            visited[cur * 2] = true;
            q.push(make_pair(cur * 2, cnt + 1));
        }

    }
}

int main() {
    cin >> n >> k;
    bfs();
    cout << ans;
}


