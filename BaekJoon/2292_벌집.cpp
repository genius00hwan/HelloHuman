#include<iostream>
using namespace std;

int n;
int temp = 1;
int cnt = 1;
int main(){
    cin >> n;
    while(n>temp){
        temp += 6 * cnt;
        cnt++;
    }
    cout << cnt ;
}