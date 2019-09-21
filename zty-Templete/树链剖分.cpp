#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int dep[N],siz[N],f[N];
int h[N],nxt[N],to[N],cnt,w[N];
int son[N],id[N],ncnt,wt[N],top[N];
int n,m,Rt;
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
int a[N<<2],laz[N<<2];
void build(int o,int l,int r){
    if(l==r){a[o]=wt[l];return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
}
inline void pushdown(int o,int len){
    laz[lt]+=laz[o];
    laz[rt]+=laz[o];
    a[lt]+=laz[o]*(len-(len>>1));
    a[rt]+=laz[o]*(len>>1);
    laz[o]=0;
}
int query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    if(laz[o])pushdown(o,r-l+1);
    int ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
void update(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){laz[o]+=k;a[o]+=k*(r-l+1);return;}
    if(laz[o])pushdown(o,r-l+1);
    if(L<=mid)update(lson,L,R,k);
    if(R>mid)update(rson,L,R,k);
    a[o]=a[lt]+a[rt];
}
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
        if(siz[v]>maxson)son[u]=v,maxson=siz[v];
    }
}
void dfs2(int u,int topf){
    id[u]=++ncnt;
    wt[ncnt]=w[u];
    top[u]=topf;
    if(!son[u])return;
    dfs2(son[u],topf);
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==f[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
int qRange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=query(1,1,n,id[top[x]],id[x]);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=query(1,1,n,id[x],id[y]);
    return ans;
}
int qSon(int x){
    return query(1,1,n,id[x],id[x]+siz[x]-1);
}
void updRange(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,id[top[x]],id[x],k);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],k);
}
void updSon(int x,int k){
    update(1,1,n,id[x],id[x]+siz[x]-1,k);
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    int x=0;char ch=nc();
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
    return x;
}
void add_edge(int u,int v){
    ++cnt;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int main(){
    n=read();m=read();Rt=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(Rt,0,1);
    dfs2(Rt,Rt);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt=read(),x,y,k;
        switch(opt){
            case 1:
                x=read(),y=read(),k=read();
                updRange(x,y,k);
                break;
            case 2:
                x=read();y=read();
                printf("%d\n",qRange(x,y));
                break;
            case 3:
                x=read();k=read();
                updSon(x,k);
                break;
            case 4:
                x=read();
                printf("%d\n",qSon(x));
                break;
        }
    }
    return 0;
}