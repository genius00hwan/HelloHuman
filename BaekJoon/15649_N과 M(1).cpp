//#include <iostream>
//#include <vector>
//
//using namespace std;
//int n,m,x,a,b;
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin>>n>>m;
//    vector<long>arr(n+1);
//    for(int i=1;i<=n;i++){
//        cin>>x;
//        arr[i] = arr[i-1] + x;
//    }
//    while (m--){
//        cin>>a>>b;
//        cout<<arr[b]-arr[a-1]<<endl;
//    }
//
//    return 0;
//}

#include<iostream>
using namespace std;
int n,m;

int arr[9] ={0,};
bool visit[9]={false,};
void dfs(int c){
    if(c==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i] = true;
            arr[c] = i;
            dfs(c+1);
            visit[i] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    dfs(0);
    return 0;
}