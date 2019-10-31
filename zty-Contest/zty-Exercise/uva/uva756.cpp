//uva756
//[数学]
//中国剩余定理
//zty111
#include<cstdio>
#include<iostream>
using namespace std;
typedef int ll;
void gcd(ll a,ll b,ll & d,ll& x,ll &y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int D,t;
ll china(int n,int * a,int * m)
{
    ll M=1,d,y,x=0;
    for(int i=0;i<n;i++)M*=m[i];
    for(int i=0;i<n;i++)
    {
        ll w=M/m[i];
        gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
    }
    if(x<=D)return M-(D-x);
    else return x-D;
}
int m[]={23,28,33};
int a[3];
int main()
{
    while(1)
    {
        t++;
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&D);
        if(a[0]==-1&&a[1]==-1&&a[2]==-1&&D==-1)break;
        int ans=china(3,a,m);
        printf("Case %d: the next triple peak occurs in %d days.\n",t,ans);
    }
    return 0;
}