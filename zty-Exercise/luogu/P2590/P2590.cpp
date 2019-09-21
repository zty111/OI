#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int dep[N],siz[N],f[N];
int h[N],nxt[N],to[N],cnt;
int son[N],id[N],ncnt,top[N];
int n,m,Rt,w[N],wt[N];
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
int a[N<<2],cmax[N<<2];
void build(int o,int l,int r){
    if(l==r){a[o]=cmax[o]=wt[l];return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
    cmax[o]=max(cmax[lt],cmax[rt]);
}
int query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    int ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
int Query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return cmax[o];
    int ans=-0x3f3f3f3f;
    if(L<=mid)ans=max(ans,Query(lson,L,R));
    if(R>mid)ans=max(ans,Query(rson,L,R));
    return ans;
}
void update(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){a[o]=k*(r-l+1);cmax[o]=k;return;}
    if(L<=mid)update(lson,L,R,k);
    if(R>mid)update(rson,L,R,k);
    a[o]=a[lt]+a[rt];
    cmax[o]=max(cmax[lt],cmax[rt]);
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
int qMax(int x,int y){
    int ans=-0x3f3f3f3f;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans=max(ans,Query(1,1,n,id[top[x]],id[x]));
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans=max(ans,Query(1,1,n,id[x],id[y]));
    return ans;
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
void add_edge(int u,int v){
    ++cnt;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int main(){
    scanf("%d",&n);Rt=1;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    scanf("%d",&m);
    dfs1(Rt,0,1);
    dfs2(Rt,Rt);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int x,y;char str[10];
        scanf("%s",str);
        scanf("%d%d",&x,&y);
        if(strcmp(str,"CHANGE")==0){
            updRange(x,x,y);
        }
        else if(strcmp(str,"QSUM")==0){
            printf("%d\n",qRange(x,y));
        }
        else if(strcmp(str,"QMAX")==0){
            printf("%d\n",qMax(x,y));
        }
    }
    return 0;
}