#include<bits/stdc++.h>
using namespace std;
const int N = 30010;
const int inf = 10000010;
int n,k,m;
int h[N],e[N],to[N],nxt[N],cnt=1,vis[N],d[N],pre[N],ans,rt,sum;
int maxp[N],s[N],rem[N],dis[N],query[N],test[inf],judge[inf],q[N];
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
        if(v==fa||vis[v])continue;
        getrt(v,u);
        s[u]+=s[v];
        maxp[u]=max(maxp[u],s[v]);
    }
    maxp[u]=max(maxp[u],sum-s[u]);
    if(maxp[u]<maxp[rt])rt=u;
}
void getdis(int u,int fa){
    rem[++rem[0]]=dis[u];
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa||vis[v])continue;
        dis[v]=dis[u]+e[i];
        getdis(v,u);
    }
}
void calc(int u){
    int p=0;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        rem[0]=0;dis[v]=e[i];
        getdis(v,u);
        for(int j=rem[0];j;--j)
            for(int k=1;k<=m;k++)
                if(query[k]>=rem[j])
                    test[k]|=judge[query[k]-rem[j]];
        for(int j=rem[0];j;--j)
            q[++p]=rem[j],judge[rem[j]]=1;
    }
    for(int i=1;i<=p;i++)
        judge[q[i]]=0;
}
void solve(int u){
    vis[u]=judge[0]=1;calc(u);
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        sum=s[v];maxp[rt=0]=inf;
        getrt(v,0);solve(rt);
    }
}
int main(){
    n=read();m=read();
    for(int i=1;i<n;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    for(int i=1;i<=m;i++)query[i]=read();
    maxp[rt]=sum=n;
    getrt(1,0);
    solve(rt);
    for(int i=1;i<=m;i++){
        if(test[i])printf("AYE\n");
        else printf("NAY\n");
    }
    return 0;
}