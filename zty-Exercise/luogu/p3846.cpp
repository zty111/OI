// p3846 可爱的质数
//[数学]
//BSGS
//zty111
#include<bits/stdc++.h>
using namespace std;
long long p,b,n;
inline long long mul_mod(long long a,long long b,long long n)
{
    return a*b%n;
}
inline long long pow_mod(long long a,long long p,long long n)
{
    long long ret=1;
    while(p)
    {
        if(p&1)ret=mul_mod(ret,a,n);
        a=mul_mod(a,a,n);
        p>>=1;
    }
    return ret;
}
void gcd(long long a,long long b,long long & d,long long & x,long long & y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
inline long long inv(long long a,long long n)
{
    long long d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}
long long log_mod(long long a,long long b,long long n)
{
    long long m,v,e=1,i;
    m=(long long)sqrt(n+0.5);
    v=inv(pow_mod(a,m,n),n);
    map<long long,long long>x;
    x[1]=0;
    for(i=1;i<m;i++)
    {
        e=mul_mod(e,a,n);
        if(!x.count(e))x[e]=i;
    }
    for(i=0;i<m;i++)
    {
        if(x.count(b))return i*m+x[b];
        b=mul_mod(b,v,n);
    }
    return -1;
}
int main()
{
    scanf("%lld%lld%lld",&p,&b,&n);
    long long ans=log_mod(b,n,p);
    if(ans==-1)printf("no solution\n");
    else printf("%lld\n",ans);
    return 0;
}