// p4720 扩展卢卡斯定理
//[数学]
//扩展卢卡斯 excrt
//zty111
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
ll a[N],c[N],n,m,p,cnt;
void exgcd(ll a,ll b,ll & d,ll & x,ll & y){
    if(!b){x=1;d=a;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
inline ll inv(ll a,ll b){
    ll x,y,d;
    exgcd(a,b,d,x,y);
    return (x%b+b)%b;
}
inline ll qpow(ll a,ll b,ll p){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }return ret;
}
inline ll crt(){
    ll M=1,ans=0;
    for(int i=0;i<cnt;i++)
        M=M*c[i];
    for(int i=0;i<cnt;i++)
        ans=(ans+a[i]*(M/c[i])%M*inv(M/c[i],c[i])%M)%M;
    return ans;
}
ll fac(ll n,ll p,ll pk){
    if(!n)return 1;
    ll ans=1;
    for(int i=1;i<pk;i++)
        if(i%p)ans=ans*i%pk;
    ans=qpow(ans,n/pk,pk);
    for(int i=1;i<=n%pk;i++)
        if(i%p)ans=ans*i%pk;
    return ans*fac(n/p,p,pk)%pk;
}
ll C(ll n,ll m,ll p,ll pk){
    if(n<m)return 0;
    ll f1=fac(n,p,pk),f2=fac(m,p,pk),f3=fac(n-m,p,pk),cnt=0;
    for(ll i=n;i;i/=p)cnt+=i/p;
    for(ll i=m;i;i/=p)cnt-=i/p;
    for(ll i=n-m;i;i/=p)cnt-=i/p;
    return f1*inv(f2,pk)%pk*inv(f3,pk)%pk*qpow(p,cnt,pk)%pk;
}
ll exlucas(ll n,ll m,ll p){
    ll tmp=sqrt(p);
    for(int i=2;p>1&&i<=tmp;i++){
        ll tmp=1;
        while(p%i==0)p/=i,tmp*=i;
        if(tmp>1)c[cnt]=tmp,a[cnt++]=C(n,m,i,tmp);
    }
    if(p>1)c[cnt]=p,a[cnt++]=C(n,m,p,p);
    return crt();
}
int main(){
    scanf("%lld %lld %lld",&n,&m,&p);
    printf("%lld\n",exlucas(n,m,p));
    return 0;
}