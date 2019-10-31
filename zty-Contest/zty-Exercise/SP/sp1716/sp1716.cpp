#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define mid ((l+r)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define lt (o<<1)
#define rt (o<<1|1)
struct tree{
    int sum,lmax,rmax,dat;
}a[maxn<<2];
inline int read(){
    int x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void update(int o){
    a[o].sum=a[lt].sum+a[rt].sum;
    a[o].lmax=max(a[lt].lmax,a[lt].sum+a[rt].lmax);
    a[o].rmax=max(a[rt].rmax,a[rt].sum+a[lt].rmax);
    a[o].dat=max(a[lt].dat,a[rt].dat);
    a[o].dat=max(a[o].dat,a[lt].rmax+a[rt].lmax);
}
void build(int o,int l,int r){
    if(l==r){a[o].dat=a[o].sum=a[o].lmax=a[o].rmax=read();return;}
    build(lson);build(rson);
    update(o);
}
tree query(int o,int l,int r,int L,int R){
    if(L<=l&&R>=r)return a[o];
    if(L>mid)return query(rson,L,R);
    if(R<=mid)return query(lson,L,R);
    else{
        tree ans,a,b;
        a=query(lson,L,R);b=query(rson,L,R);
        ans.sum=a.sum+b.sum;
        ans.dat=max(a.dat,b.dat);
        ans.dat=max(ans.dat,a.rmax+b.lmax);
        ans.lmax=max(a.lmax,a.sum+b.lmax);
        ans.rmax=max(b.rmax,b.sum+a.rmax);
    }
}

int n,m,x,y;
int main(){
    n=read();
    build(1,1,n);
    m=read();
    for(int i=1;i<=m;i++){
        x=read();y=read();
        printf("%d\n",query(1,1,n,x,y).dat);
    }
    return 0;
}