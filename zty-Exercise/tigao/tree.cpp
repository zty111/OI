#include<cstdio>
using namespace std;
const int N = 100010;
#define mid ((l+r)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define len (r-l+1)
#define lt (o<<1)
#define rt (o<<1|1)
typedef long long ll;
ll a[N<<2],laz[N<<2],wt[N],n,m;
void build(int o,int l,int r){
    if(l==r){a[o]=wt[l];return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
}
void pushdown(int o,int lenn){
    laz[lt]+=laz[o];laz[rt]+=laz[o];
    a[lt]+=laz[o]*(lenn-(lenn>>1));
    a[rt]+=laz[o]*(lenn>>1);
    laz[o]=0;
}
ll query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    if(laz[o])pushdown(o,len);
    ll ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>=mid+1)ans+=query(rson,L,R);
    return ans;
}
void update(int o,int l,int r,int L,int R,ll k){
    if(L<=l&&r<=R){laz[o]+=k;a[o]+=k*len;return;}
    if(laz[o])pushdown(o,len);
    if(L<=mid)update(lson,L,R,k);
    if(R>=mid+1)update(rson,L,R,k);
    a[o]=a[lt]+a[rt];
}
inline void read(ll & x){
    x=0;char ch=getchar();int flag=1;
    while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    x*=flag;
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++)read(wt[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        ll flag;read(flag);
        if(flag==1){
            ll x,y,k;
            read(x);read(y);read(k);
            update(1,1,n,x,y,k);
        }
        else{
            ll x,y;
            read(x);read(y);
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}