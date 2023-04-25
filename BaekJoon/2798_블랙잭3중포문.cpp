#include<iostream>
using namespace std;

int n,m,sum,result;
int deck[100];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>deck[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                sum = deck[i]+deck[j]+deck[k];
                if(sum<=m&&sum>=result) result = sum;
            }
        }
    }
    cout<<result;
}