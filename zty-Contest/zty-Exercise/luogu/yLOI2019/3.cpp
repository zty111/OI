#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,type,p;
int main(){
    cin>>type>>n>>m>>p;
    ll ans=1;
    for(ll i=n-2*m+2;i<=n-m+1;i++)ans=ans*i%p;
    cout<<ans<<endl;
    return 0;
}