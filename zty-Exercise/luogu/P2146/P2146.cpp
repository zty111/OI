#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int h[N],nxt[N<<1],to[N<<1],cnt;
void add_edge(int u,int v){
    ++cnt;nxt[cnt]=h[u];h[u]=cnt;to[cnt]=v;
}
int son[N],siz[N],f[N],dep[N];
void dfs1(int u,int fa,int deep){
    f[u]=fa;siz[u]=1;dep[u]=deep;
    int maxson=-1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa)continue;
        dfs1(v,u,deep+1);
        siz[u]+=siz[v];
        if(siz[v]>maxson)maxson=siz[v],son[u]=v;
    }
}
int id[N],top[N],num;
void dfs2(int u,int topf){
    id[u]=++num;
    top[u]=topf;
    if(!son[u])return;
    dfs2(son[u],topf);
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v==f[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
int a[N<<2],laz[N<<2];
void build(int o,int l,int r){
    if(l==r){a[o]=1;return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
}
void pushdown(int o,int len){
    laz[lt]=laz[o];
    laz[rt]=laz[o];
    a[lt]=laz[o]*(len-(len>>1));
    a[rt]=laz[o]*(len>>1);
    laz[o]=-1;
}
int query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    int ans=0;
    if(laz[o]!=-1)pushdown(o,r-l+1);
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
void update(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){a[o]=k*(r-l+1);laz[o]=k;return;}
    if(laz[o]!=-1)pushdown(o,r-l+1);
    if(L<=mid)update(lson,L,R,k);
    if(R>mid)update(rson,L,R,k);
    a[o]=a[lt]+a[rt];
}
int n,root,m;
int askSon(int x){
    return siz[x]-query(1,1,n,id[x],id[x]+siz[x]-1);
}
int askRange(int x,int y){
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
void updSon(int x){
    update(1,1,n,id[x],id[x]+siz[x]-1,1);
}
void updRange(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,id[top[x]],id[x],0);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],0);
}
char s[20];
int main(){
    scanf("%d",&n);root=1;
    for(int i=2;i<=n;i++){
        int v;scanf("%d",&v);
        v++;
        add_edge(i,v);
        add_edge(v,i);
    }
    dfs1(root,0,1);
    dfs2(root,root);
    build(1,1,n);
    memset(laz,-1,sizeof(laz));
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int v,ans;
        scanf("%s %d",s+1,&v);
        v++;
        if(s[1]=='i'){
            ans=askRange(v,root);
            updRange(v,root);
        }
        else{
            ans=askSon(v);
            updSon(v);
        }
        printf("%d\n",ans);
    }
    return 0;
}