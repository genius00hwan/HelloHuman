#include <iostream>
using namespace std;

int n,sum;
string str;
int main() {
   cin>>n>>str;
   for(int i=0;i<n;i++){
       sum+=(int)(str[i]-'0');
   }
   cout<<sum;
}