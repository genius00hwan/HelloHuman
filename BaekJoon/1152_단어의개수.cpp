#include <iostream>
#include <string>
using namespace std;

string str;
int num;


int main(){
    getline(cin,str);
    if(str.length()==0||(str.length()==1&&str[0]==' ')){cout<<0; return 0;}
    for(int i=0;i<=str.length();i++){
        if(i!=0&&i!=str.length()-1&&str[i]==' ')num++;
    }
    cout<<num+1<<endl;
    return 0;
}