// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll FP(ll a,ll k,ll mod)
{
    ll ans=1;
    for(;k;k>>=1,a=a*a%mod)
    if(k&1) ans=ans*a%mod;
    return ans;
}

ll ExGCD(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
		x=1;
        y=0;
        return a;
    }
    ll gcd=ExGCD(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return gcd;
}

ll inv(ll n,ll mod)
{
    long long x;
    long long y;
    ExGCD(n,mod,x,y);
    x+=mod;
    if(x<=mod) return x;
    return x-mod;
}

ll n,m,p;

ll CRT(ll a,ll mod)
{
    ll ans=a;
    ans=ans*inv(p/mod,mod)%p;
    ans=ans*(p/mod)%p;
    return ans;
}

ll fac(ll n,ll pi,ll pk)
{
    if(!n) return 1;
    ll ans=1;
    for(ll i=2;i<=pk;i++)
    {
        if(i%pi==0) continue;
        ans=ans*i%pk;
    }
    ans=FP(ans,n/pk,pk);
    for(ll i=2;i<=n%pk;i++)
    {
        if(i%pi==0) continue;
        ans=ans*i%pk;
    }
    return ans*fac(n/pi,pi,pk)%pk;
}

ll C(ll n,ll m,ll pi,ll pk)
{
    ll a=fac(n,pi,pk);
    ll d1=fac(m,pi,pk);
    ll d2=fac(n-m,pi,pk);
    ll k=0;
    for(ll i=n;i;i/=pi) k+=i/pi;
    for(ll i=m;i;i/=pi) k-=i/pi;
    for(ll i=n-m;i;i/=pi) k-=i/pi;
    ll ans=a;
    ans=ans*inv(d1,pk)%pk;
    ans=ans*inv(d2,pk)%pk;
    ans=ans*FP(pi,k,pk)%pk;
    return ans;
}

ll ExLucas(ll n,ll m)
{
    ll ans=0;
    ll tmp=p;
    ll pk=0;
    static int len=sqrt(p)+5;
    for(int i=2;i<=len;i++)
    {
        if(tmp%i) continue;
        pk=1;
        while(tmp%i==0)
        {
            pk*=i;
            tmp/=i;
        }
        ans=(ans+CRT(C(n,m,i,pk),pk))%p;
    }
    if(tmp>1) ans=(ans+CRT(C(n,m,tmp,tmp),tmp))%p;
    return ans;
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&p);
    ll ans=ExLucas(n,m);
    printf("%lld\n",ans);
    return 0;
}
