#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
typedef long long ll;
ll a[N<<2],laz[N<<2];
int wt[N];
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
ll query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    if(laz[o])pushdown(o,r-l+1);
    ll ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
void update(int o,int l,int r,int L,int R,ll k){
    if(L<=l&&r<=R){laz[o]+=k;a[o]+=k*(r-l+1);return;}
    if(laz[o])pushdown(o,r-l+1);
    if(L<=mid)update(lson,L,R,k);
    if(R>mid)update(rson,L,R,k);
    a[o]=a[lt]+a[rt];
}
int n,m;
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
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)wt[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt=read();
        if(opt==1){
            int x=read(),y=read(),k=read();
            update(1,1,n,x,y,k);
        }
        else{
            int x=read(),y=read();
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}