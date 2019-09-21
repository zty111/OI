// p4549 裴蜀定理
//[数学]
//扩展中国剩余定理
//zty111
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
ll a[N],b[N];
int n;
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
void gcd(ll a,ll b,ll & d,ll& x,ll &y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
ll excrt()
{
    ll M=a[0],x,d,y,ans=b[0];
    for(int i=1;i<n;i++)
    {
        gcd(M,a[i],d,x,y);
        ll mg=a[i]/d,c=(b[i]-ans%a[i]+a[i])%a[i];
        if(c%d!=0)return -1;

        x=qmul(x,c/d,mg);
        ans+=x*M;
        M*=mg;
        ans=(ans%M+M)%M;
    }
    return (ans%M+M)%M;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    printf("%lld\n",excrt());
    return 0;
}