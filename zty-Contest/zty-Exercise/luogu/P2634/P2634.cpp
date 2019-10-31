#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int mod = 3;
int n;
int h[N],e[N],to[N],nxt[N],cnt=1,vis[N],rt,su;
long long ans;
int maxp[N],s[N],dis[N],r,sum[4];
void add_edge(int u,int v,int d){
    to[++cnt]=v;
    e[cnt]=d;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
void getrt(int u,int fa){
    s[u]=1;maxp[u]=0;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v]||v==fa)continue;
        getrt(v,u);
        s[u]=s[u]+s[v];
        maxp[u]=max(maxp[u],s[v]);
    }
    maxp[u]=max(maxp[u],su-s[u]);
    if(maxp[u]<maxp[rt])rt=u;
}
void query(int u,int fa,int d){
    ++sum[d%mod];
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v]||v==fa)continue;
        query(v,u,(d+e[i])%mod);
    }
}
long long solve(int u,int d){
    sum[0]=sum[1]=sum[2]=0;
    query(u,0,d);
    long long res=1ll*sum[1]*sum[2]*2+1ll*sum[0]*sum[0];
    return res;
}
void divide(int u){
    ans+=solve(u,0);
    vis[u]=1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        ans-=solve(v,e[i]);
        su=s[v],maxp[0]=n,rt=0;
        getrt(v,0);
        divide(rt);
    }
}
long long gcd(long long a,long long b){
    while(b^=a^=b^=a%=b);
    return a;
}
int main(){
    n=read();
    maxp[0]=su=n;
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        a=read();b=read();c=read();
        add_edge(a,b,c%3);
        add_edge(b,a,c%3);
    }
    getrt(1,0);
    divide(rt);
    long long p=n*n,GCD=gcd(ans,p);
    printf("%lld/%lld\n",ans/GCD,p/GCD);
    return 0;
}