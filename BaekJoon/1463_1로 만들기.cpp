#include <iostream>

#define MAX 1000002

using namespace std;

int n;
int dp[MAX] = {0, 0,1,1,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int mul3 = 3 * i;
        int mul2 = 2 * i;
        int plus1 = 1 + i;

        if (dp[i] + 1 < dp[plus1] || dp[plus1] == 0)
            dp[plus1] = dp[i] + 1;
        if (mul2 > n) continue;
        if (dp[i] + 1 < dp[mul2] || dp[mul2] == 0)
            dp[mul2] = dp[i] + 1;
        if (mul3 > n) continue;
        if (dp[i] + 1 < dp[mul3] || dp[mul3] == 0)
            dp[mul3] = dp[i] + 1;
//        cout<<i<<" "<<dp[i]<<" "<<mul3<<" "<<dp[mul3]<<endl;
//        cout<<i<<" "<<dp[i]<<" "<<mul2<<" "<<dp[mul2]<<endl;
//        cout<<i<<" "<<dp[i]<<" "<<plus1<<" "<<dp[plus1]<<endl;


    }
    cout << dp[n];

    return 0;
}
