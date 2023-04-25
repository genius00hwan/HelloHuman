

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m; //n이 a, m이 b
int ans;

vector<int> A;
vector<int> B;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.emplace_back(a);
    }
    for (int j = 0; j < m; j++) {
        int b;
        cin >> b;
        B.emplace_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void solve() {

    ans = 0;
    for (int a: A) {
        int left = 0;
        int right = m ;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (a > B[mid]) left = mid;
            else right = mid;
        }
        ans += left;
        if (a > B[left])ans++;
    }
    cout << ans<<"\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        input();
        solve();
        ans = 0;
        A.clear();
        B.clear();
    }
}