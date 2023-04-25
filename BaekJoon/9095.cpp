#include <iostream>

#define MAX 1000002

using namespace std;

int t, n;
int dp[MAX] = {0, 1, 2, 4,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n]<<endl;
    }

    return 0;
}
