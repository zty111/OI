#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long a;
        cin>>a;
        if(a%2==0&&(a+2)%3==0)cout<<a<<endl;
        else cout<<a-1<<endl;
    }
    return 0;
}