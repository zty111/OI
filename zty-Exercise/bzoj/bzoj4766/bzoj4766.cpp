// bzoj4766 文艺计算姬
//[数学]
//快速幂与快速乘
//zty111

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qmul(ll a,ll b,ll p)
{
    ll ret=0;
    while(b)
    {
        if(b&1)ret=(ret+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}
ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=qmul(ret,a,p);
        a=qmul(a,a,p);
        b>>=1;
    }
    return ret;
}
ll a,b,p;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld",qmul(qpow(a,b-1,p),qpow(b,a-1,p),p));
    return 0;
}