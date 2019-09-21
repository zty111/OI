#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
ll qpow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }return ret;
}
ll j(ll a){
    if(a==0)return 1;
    else return j(a-1)*a%mod;
}
ll inv(ll a){
    return qpow(a,mod-2);
}
ll n;
int main(){
    scanf("%lld",&n);
    ll ans=j(2*n)*inv(j(n))%mod*inv(j(n))%mod*inv(n+1)%mod;
    printf("%lld\n",ans);
    return 0;
}