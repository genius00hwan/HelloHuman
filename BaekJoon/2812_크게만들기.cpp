#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> deq;
string num;
int n, k, cnt;


void input() {
    cin >> n >> k;
    cin >> num;
}

void solve() {
    for(int i=0;i<n;i++){
        while (!deq.empty()&& k&& num[i]-'0'>deq.back()){
            deq.pop_back();
            k--;
        }
        deq.push_back(num[i]-'0');
    }
    while (!deq.empty() && cnt != k){
        deq.pop_back();
        k--;
    }
    while (!deq.empty() ){
        cout<<deq.front();
        deq.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}

