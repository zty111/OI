// p2261 余数求和
//[数学]
//整除分块
//zty111
#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    ans=n*k;
    for(long long l=1,r,t;l<=n;l=r+1)
    {
        t=k/l;
        if(t!=0)r=min(k/t,n);
        else r=n;
        ans-=t*(r-l+1)*(r+l)/2;
    }
    printf("%lld\n",ans);
    return 0;
}