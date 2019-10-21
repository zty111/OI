#include<bits/stdc++.h>

using namespace std;

#define int long long

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

inline int read(){
    int x=0,f=1;
    char p=getchar();
    while(!isdigit(p)){
        if(p=='-') f=-1;
        p=getchar();
    }
    while(isdigit(p)) x=(x<<3)+(x<<1)+p-48,p=getchar();
    return x*f;
}

long long ans;

const int maxn=5e5+5,mod=1e9+7;

int s[maxn<<2],low[maxn<<2],dfn[maxn<<2],n,b[maxn],a[maxn],tot;
int x[maxn],tree[maxn<<2],headedge[maxn<<2],veredge[maxn<<2];
int head[maxn<<2],nxt[maxn*25],ver[maxn*25],scc,col[maxn<<2];
int v[maxn<<2],id[maxn],cnt,top,nxtedge[maxn<<2],cntedge;
int w[maxn<<2],nod,rd[maxn<<2],f[maxn<<2];
map<pair<int,int>,int> Map;

inline void add(int x,int y){
    nxt[++cnt]=head[x];
    head[x]=cnt;
    ver[cnt]=y;
}

inline void addedge(int x,int y){
    nxtedge[++cntedge]=headedge[x];
    headedge[x]=cntedge;
    veredge[cntedge]=y;
}

inline void build(int k,int l,int r){
    if(l==r){
        nod=max(nod,k);
        id[l]=k;
        return;
    }
    build(lson);
    build(rson);
    add(k,k<<1);
    add(k,k<<1|1);
}

inline void connect(int k,int l,int r,int L,int R,int pos){
    if(L<=l&&r<=R){
        if(id[pos]==k) return;
        add(id[pos],k);
        return;
    }
    if(L<=mid) connect(lson,L,R,pos);
    if(R>mid) connect(rson,L,R,pos);
    return;
}

inline void tarjan(int x){
    dfn[x]=low[x]=++tot;
    s[++top]=x;
    v[x]=1;
    for(int i=head[x];i;i=nxt[i]){
        int y=ver[i];
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(v[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        int tmp;
        scc++;
        do{
            tmp=s[top--];
            col[tmp]=scc;
            v[tmp]=0;

        }while(x!=tmp);
    }
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++) b[i]=a[i]=read(),x[i]=read();
    //线段树 
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int l=lower_bound(b+1,b+1+n,a[i]-x[i])-b;
        int r=(upper_bound(b+1,b+1+n,a[i]+x[i])-b)-1;
        connect(1,1,n,l,r,i);
    }
    //tarjan 
    for(int i=1;i<=nod;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) w[col[id[i]]]++;
    //连边 
    for(int x=1;x<=nod;x++){
        for(int i=head[x];i;i=nxt[i]){
            int y=ver[i];
            if(col[x]==col[y]) continue;
            pair<int,int> t;
            t.first=col[y],t.second=col[x];
            if(Map[t]==1) continue;
            addedge(col[y],col[x]);
            Map[t]=1;
            ++rd[col[x]];
        }
    }
    //topsort 
    queue<int> q;
    for(int i=1;i<=scc;i++) if(rd[i]==0) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        f[x]+=w[x];
        for(int i=headedge[x];i;i=nxtedge[i]){
            int y=veredge[i];
            f[y]+=f[x];
            rd[y]--;
            if(rd[y]==0) q.push(y);
        }
    }
    //统计答案 
    for(int i=1;i<=n;i++) ans=(ans+i*f[col[id[i]]]%mod)%mod, cout<<ans<<endl;
    cout<<ans<<endl;
    return 0;
}