#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 100003;
ll qpow(ll a,ll b){
    a%=mod;
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }return ret;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&m,&n);
    ll ans=qpow(m,n)-m*qpow(m-1,n-1)%mod;
    printf("%lld",(ans+mod)%mod);
    return 0;
}