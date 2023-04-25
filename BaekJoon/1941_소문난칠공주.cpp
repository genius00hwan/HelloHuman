#include <iostream>
#include <vector>
#include <algorithm>

#define N 5
using namespace std;

int ans;

bool dasom[27];
bool visited[27];
bool seat[26][26];
vector<int> princess;

void init() {
    for (int i = 0; i < 24; i++) {
        if (i % 5 != 4 || (i + 1) % 5 != 0) {
            seat[i][i + 1] = true;
            seat[i + 1][i] = true;
        }
        if (i < 20) {
            seat[i][i + 5] = true;
            seat[i + 5][i] = true;
        }
    }
}

void dfs(int g) {
    visited[g] = true;
    for (auto p: princess) {
        if (seat[g][p] && !visited[p]) {
            dfs(p);
        }
    }
}

bool check() {
    int cnt = 0;
    for (int p: princess) {
        if (!visited[p]) {
            dfs(p);
            cnt++;
        }
    }
    if (cnt == 1) {
        int somN = 0;
        for (int p: princess) {
            if (dasom[p])
                somN++;
        }
        if (somN >= 4) return true;
    }
    return false;
}

void pickedSeat() {
    vector<int> idx;

    for (int i = 0; i < 7; i++) idx.emplace_back(1);
    for (int i = 0; i < 18; i++) idx.emplace_back(0);
    sort(idx.begin(), idx.end());
    do {
        for (int i = 0; i < idx.size(); i++) {
            if (idx[i]) {
                princess.emplace_back(i);
            }
        }
        if (check())
            ans++;
        princess.clear();
        for (int i = 0; i < 25; i++) visited[i] = false;

    } while (next_permutation(idx.begin(), idx.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string row;
    init();
    for (int i = 0; i < 5; i++) {
        cin >> row;
        for (int j = 0; j < 5; j++) {
            if (row[j] == 'S')
                dasom[j + (i * 5)] = true;
        }
    }

    pickedSeat();
    cout << ans << endl;
}