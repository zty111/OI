#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll wt[N],a[N<<2],laz[N<<2];
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
#define len (r-l+1)
void build(int o,int l,int r){
    if(l==r){a[o]=laz[o]=wt[l];return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
    laz[o]=max(laz[lt],laz[rt]);
}
void update(int o,int l,int r,int L,int R){
    if(l==r){a[o]=laz[o]=sqrt(a[o]);return;}
    if(L<=mid&&laz[lt]>1)update(lson,L,R);
    if(R>=mid+1&&laz[rt]>1)update(rson,L,R);
    a[o]=a[lt]+a[rt];
    laz[o]=max(laz[lt],laz[rt]);
}
ll query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    ll ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>=mid+1)ans+=query(rson,L,R);
    return ans;
}
int n,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&wt[i]);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(x>y)swap(x,y);
        if(k==0)update(1,1,n,x,y);
        else printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}