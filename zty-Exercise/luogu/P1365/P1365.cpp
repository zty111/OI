#include<bits/stdc++.h>
using namespace std;
long double ans,p,x;
int n;char ch;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch;
        if(ch=='?')p=0.5;
        else if(ch=='o')p=1;
        else if(ch=='x')p=0;
        ans+=(2*x+1)*p;
        x=(x+1)*p;
    }
    cout<<fixed<<setprecision(4)<<ans;
    return 0;
}