#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int h[N],to[N<<1],nxt[N<<1],cnt;
void add_edge(int u,int v){
    ++cnt;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int siz[N],f[N],son[N],dep[N];
void dfs1(int u,int fa,int deep){
    dep[u]=deep;
    f[u]=fa;
    siz[u]=1;
    int maxson=-1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa)continue;
        dfs1(v,u,deep+1);
        siz[u]+=siz[v];
        if(siz[v]>maxson)maxson=siz[v],son[u]=v;
    }
}
int top[N];
void dfs2(int u,int topf){
    top[u]=topf;
    if(!son[u])return;
    dfs2(son[u],topf);
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==f[u]||v==son[u])continue;
        dfs2(v,v);
    }    
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    return x;
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
int n, m, d[N], ans;
int dfs(int u) {
    int now = d[u];
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u]) continue;
        now += dfs(v);
    }
    ans = max(ans, now);
    return now;
}
int main(){
    n=read();m=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        int z = lca(x, y);
        d[x]++; d[y]++;
        d[z]--; d[f[z]]--;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}