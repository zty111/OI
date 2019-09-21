// p1516 青蛙的约会
//[数学]
//exgcd
//zty111
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void gcd(ll a,ll b,ll & d,ll & x,ll & y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
ll x,y,m,n,L;
ll a,b,c,d,e,dd,mod;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
    a=n-m;b=L;dd=x-y;
    gcd(a,b,d,c,e);
    mod=abs(L/d);
    if(dd%d!=0)printf("Impossible\n");
    else{
        printf("%lld\n",(c*(dd/d)%mod+mod)%mod);
    }
    return 0;
}