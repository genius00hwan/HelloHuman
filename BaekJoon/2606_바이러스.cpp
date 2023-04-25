//
// Created by 김수환 on 2022/12/25.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt;
bool visited[101];
vector<int> edge[101];

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        cnt++;
        for (int v: edge[x]) {
            if (!visited[v])
                q.push(v);
        }
    }
}

void init(int m) {
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    init(m);
    bfs();
    cout<<cnt-1;
    return 0;
}
