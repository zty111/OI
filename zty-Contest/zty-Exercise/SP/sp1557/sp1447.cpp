#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
#define mid ((l+r)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define lc (o<<1)
#define rc (o<<1|1)
struct tree{
    int sum,hix,stag,htag;
    tree(){sum=hix=stag=htag=0;}
    friend tree operator + (tree l,tree r){
        tree ret;
        ret.sum=max(r.sum,l.sum);
        ret.hix=max(r.hix,l.hix);
        return ret;
    }
}b[maxn<<2];
inline int read(){
    int x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct qst{
    int l,r,id;
}q[maxn];
bool cmp(qst x,qst y){
    return x.r<y.r;
}
void pushup(int o){
    b[o]=b[lc]+b[rc];
}
void pushdown(int o){
    b[lc].hix=max(b[lc].hix,b[lc].sum+b[o].htag);
    b[rc].hix=max(b[rc].hix,b[rc].sum+b[o].htag);
    b[lc].sum+=b[o].stag;
    b[rc].sum+=b[o].stag;
    b[lc].htag=max(b[lc].htag,b[lc].stag+b[o].htag);
    b[rc].htag=max(b[rc].htag,b[rc].stag+b[o].htag);
    b[lc].stag+=b[o].stag;
    b[rc].stag+=b[o].stag;
    b[o].stag=b[o].htag=0;
}
void upd(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        b[o].sum+=k;
        b[o].hix=max(b[o].hix,b[o].sum);
        b[o].stag+=k;
        b[o].htag=max(b[o].htag,b[o].stag);
        return;
    }
    pushdown(o);
    if(mid>=L)upd(lson,L,R,k);
    if(mid<R)upd(rson,L,R,k);
    pushup(o);
}
tree query(int o,int l,int r,int L,int R){
   // cout<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
    if(L<=l&&r<=R)return b[o];
    pushdown(o);
    if(mid<L)return query(rson,L,R);
    else if(mid>=R)return query(lson,L,R);
    else return query(lson,L,R)+query(rson,L,R);
}
int n,m,x,y,a[maxn],pre[maxn],mp[maxn*2],ans[maxn];
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pre[i]=mp[a[i]+100000];
        mp[a[i]+100000]=i;
    }
    m=read();
    for(int i=1;i<=m;i++){
        q[i].l=read();q[i].r=read();
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    int j=1;
    for(int i=1;i<=n;i++){
        upd(1,1,n,pre[i]+1,i,a[i]);
        for(;j<=m&&q[j].r<=i;j++){
            ans[q[j].id]=query(1,1,n,q[j].l,q[j].r).hix;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
