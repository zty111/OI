#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=400010;
ll mod,m,n;
ll sum[maxn],addv[maxn],mulv[maxn],a[maxn];
ll ql,qr,v;
void build(ll o,ll L,ll R)
{
    mulv[o]=1;
    if(L==R){sum[o]=a[L]%mod;return;}
    ll lc=o*2,rc=o*2+1;
    ll M=L+(R-L)/2;
    build(lc,L,M);
    build(rc,M+1,R);
    sum[o]=(sum[lc]+sum[rc])%mod;
}
void pushdown(ll o,ll L,ll R)
{
    ll lc=o*2,rc=o*2+1;
    ll M=L+(R-L)/2;
    sum[lc]=(sum[lc]*mulv[o]%mod+addv[o]*(M-L+1))%mod;
    sum[rc]=(sum[rc]*mulv[o]%mod+addv[o]*(R-M))%mod;
    addv[lc]=(addv[lc]*mulv[o]%mod+addv[o])%mod;
    addv[rc]=(addv[rc]*mulv[o]%mod+addv[o])%mod;
    addv[o]=0;
    mulv[lc]*=mulv[o];mulv[lc]%=mod;
    mulv[rc]*=mulv[o];mulv[rc]%=mod;
    mulv[o]=1;
}
void updatea(ll o,ll L,ll R)
{
    ll lc=o*2,rc=o*2+1;
    if(ql<=L&&qr>=R)
    {
        addv[o]=(addv[o]+v)%mod;
        sum[o]=(sum[o]+v*(R-L+1))%mod;
    }
    else
    {
        pushdown(o,L,R);
        ll M=L+(R-L)/2;
        if(ql<=M)updatea(lc,L,M);
        if(qr>M)updatea(rc,M+1,R);
        sum[o]=(sum[rc]+sum[lc])%mod;
    }
}
void updatem(ll o,ll L,ll R)
{
    ll lc=o*2,rc=o*2+1;
    if(ql<=L&&qr>=R)
    {
        mulv[o]=mulv[o]*v%mod;
        addv[o]=addv[o]*v%mod;
        sum[o]=sum[o]*v%mod;
    }
    else
    {
        pushdown(o,L,R);
        ll M=L+(R-L)/2;
        if(ql<=M)updatem(lc,L,M);
        if(qr>M)updatem(rc,M+1,R);
        sum[o]=(sum[rc]+sum[lc])%mod;
    }
}
ll query(int o,int L,int R)
{
    ll M=L+(R-L)/2,lc=o*2,rc=o*2+1;
    if(ql<=L&&R<=qr)return sum[o];
    pushdown(o,L,R);
    ll ret=0;
    if(ql<=M)ret=(ret+query(lc,L,M))%mod;
    if(qr>M)ret=(ret+query(rc,M+1,R))%mod;
    return ret%mod;
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read(){
    char ch=nc();ll sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main()
{
    n=read();mod=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    m=read();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int flag;
        flag=read();
        if(flag==2)
        {
            ql=read();qr=read();v=read();
            updatea(1,1,n);
        }
        else if(flag==3)
        {
            ql=read();qr=read();
            printf("%lld\n",query(1,1,n));
        }
        else if(flag==1)
        {
            ql=read();qr=read();v=read();
            updatem(1,1,n);
        }
    }
    return 0;
}