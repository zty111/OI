#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m;
struct Mat{
    LL m[101][101];
};
Mat a,e;
LL n,p;
Mat Mul(Mat x,Mat y)
{
    Mat c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c.m[i][j]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
        c.m[i][j]=c.m[i][j]%mod+x.m[i][k]*y.m[k][j]%mod;
    return c;
}
Mat pow_mod(Mat a,LL b)
{
    Mat ans=e;
    while(b)
    {
        if(b&1)ans=Mul(ans,a);
        a=Mul(a,a);
        b>>=1;
    }
    return ans;
}
int main()
{
    scanf("%lld %lld %lld",&n,&p,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a.m[i][j]);
    for(int i=1;i<=n;i++)
        e.m[i][i]=1;
    Mat ans=pow_mod(a,p);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%lld ",ans.m[i][j]%m);
        printf("\n");
    }
    return 0;
}