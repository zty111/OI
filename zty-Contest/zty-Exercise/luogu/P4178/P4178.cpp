#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int inf = 10000010;
int n,k,m;
int h[N],e[N],to[N],nxt[N],cnt=1,vis[N],ans,rt,sum;
int maxp[N],s[N],q[N],dis[N],r;
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
        maxp[u]=max(maxp[u],s[u]);
    }
    maxp[u]=max(maxp[u],sum-s[u]);
    if(maxp[u]<maxp[rt])rt=u;
}
void getdis(int u,int fa){
    q[++r]=dis[u];
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa||vis[v])continue;
        dis[v]=dis[u]+e[i];
        getdis(v,u);
    }
}
int solve(int u,int val){
    r=0;dis[u]=val;
    getdis(u,0);
    int sum=0,l=1;
    sort(q+1,q+1+r);
    while(l<=r){
        if(q[l]+q[r]<=k)sum+=r-l,++l;
        else --r;
    }
    return sum;
}
void divide(int u){
    ans+=solve(u,0);
    vis[u]=1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        ans-=solve(v,e[i]);
        sum=s[v],maxp[0]=n,rt=0;
        getrt(v,u);
        divide(rt);
    }
}
int main(){
    n=read();
    maxp[0]=sum=n;
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        a=read();b=read();c=read();
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    k=read();
    getrt(1,0);
    divide(rt);
    printf("%d\n",ans);
    return 0;
}