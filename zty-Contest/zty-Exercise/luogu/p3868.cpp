// p3868 猜数字
//[数学]
//中国剩余定理
//zty111
#include<bits/stdc++.h>
using namespace std;
const int N = 11;
typedef long long ll;
ll a[N],b[N];
int n;
void gcd(ll a,ll b,ll &d,ll & x,ll & y)
{
    if(!b){x=1;y=0;d=a;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
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
ll china()
{
    ll M=1,ans=0,inv,d;
    for(int i=0;i<n;i++)
        M*=b[i];
    for(int i=0;i<n;i++)
    {
        ll m=M/b[i];
        gcd(b[i],m,d,d,inv);
        inv=(inv%M+M)%M;
        a[i]=(a[i]%M+M)%M;
        ans=(ans+qmul(qmul(inv,m,M),a[i],M))%M;
    }
    return (ans+M)%M; 
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]);
    printf("%lld\n",china());
    return 0;
}