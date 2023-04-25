#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int arr[2002];
bool dp[2002][2002];
int n, m;


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = true;
        if(arr[i]==arr[i-1])
            dp[i-1][i] = true;
    }
}

void solve() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            if (dp[j + 1][j + i - 1]&&arr[j] == arr[j + i])
                dp[j][j + i] = true;
        }
    }
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}

