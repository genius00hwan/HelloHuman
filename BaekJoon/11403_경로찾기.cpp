#include <iostream>
#include <vector>

using namespace std;

bool graph[101][101];
bool ans[101][101];
bool visited[101][101];

int n;


void dfs(int first, int a) {
    for (int i = 0; i < n; i++) {
        if(ans[a][i]){
            visited[first][i] = true;
            ans[first][i] = true;
            continue;
        }
        if (!visited[first][i]&&graph[a][i]) {
            visited[first][i] = true;
            ans[first][i] = true;
            dfs(first, i);
        }
    }
}
void input(){
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool e;
            cin >> e;
            graph[i][j] = e;
        }
    }
}

void solve(){
    for (int i = 0; i < n; i++) {
        dfs(i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }cout<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}


