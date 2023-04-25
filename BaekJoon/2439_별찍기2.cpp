#include <iostream>
using namespace std;

int n;
int main() {
    cin>>n;
    int m = n;
    while(m--){
        for(int i=1;i<=m;i++)cout<<" ";
        for(int i=n-m;i>=1;i--)cout<<"*";
        cout<<endl;
    }
}