// p2842 LJJ算数
//[数学]
//费马小定理 快速幂
//zty111
#include<bits/stdc++.h>
using namespace std;
const long long p = 1000000007;
typedef long long ll;
ll qpow(ll a,ll b,ll mod)
{
    a%=mod;
    ll ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    ll a,b;
    scanf("%lld %lld",&a,&b);
    ll po=qpow(a,b-1,p-1);
    printf("%lld\n",qpow(a,po,p));
    return 0;
}