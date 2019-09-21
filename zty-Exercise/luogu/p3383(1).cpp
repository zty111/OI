#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const int N = 5;
inline ll random(ll n){
    return (ll)((double)rand()/RAND_MAX*n+0.5);
}
inline ll qpow(ll a,ll b,ll m){
    ll ret=1;
    while(b>0){
        if(b&1)ret=1ll*ret*a%m;
        b>>=1;
        a=1ll*a*a%m;
    }return ret;
}
inline bool Witness(ll a,ll n){
    ll m=n-1;int j=0;
    while(!(m&1)){j++;m>>=1;}
    ll x=qpow(a,m,n);
    if(x==1||x==n-1)return false;
    while(j--){
        x=1ll*x*x%n;
        if(x==n-1)return false;
    }return true;
}
inline bool miller_rabin(ll n){
    if(n<2)return false;
    if(n==2)return true;
    if(!(n&1))return false;
    for(ll i=1;i<=N;i++){
        ll a=random(n-2)+1;
        if(Witness(a,n))return false;
    }return true;
}
inline void read(int & a){
    a=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+ch-48;ch=getchar();}
}
int main(){
    srand(time(0));
    int n,m,a;
    read(n);read(m);
    for(int i=1;i<=m;i++){
        read(a);
        if(miller_rabin(a))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}