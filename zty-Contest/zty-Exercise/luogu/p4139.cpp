// p4139 上帝与集合的正确用法
//[数学]
//扩展欧拉定理 线性筛
//zty111
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
int phi[N];
void getphi()
{
    phi[1]=1;
    for(int i=2;i<N;i++)if(!phi[i])
        for(int j=i;j<N;j+=i)
        {
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}
int qpow(int a,int b,int p)
{
    int ret=1;
    while(b)
    {
        if(b&1)ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return ret;
}
int solve(int mod)
{
    if(mod==1)return 0;
    else return qpow(2,solve(phi[mod])+phi[mod],mod);
}
int main()
{
    getphi();
    int T,p;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&p);
        printf("%d\n",solve(p));
    }
    return 0;
}