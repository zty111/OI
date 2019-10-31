#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define mid ((l+r)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define len (r-l+1)
#define lt (o<<1)
#define rt (o<<1|1)
typedef long long ll;
ll a[maxn<<2],laz[maxn<<2],wt[maxn];
void build(int o,int l,int r)
{
    if(l==r){a[o]=laz[o]=wt[l];return;}
    build(lson);
    build(rson);
    a[o]=a[lt]+a[rt];
    laz[o]=max(laz[lt],laz[rt]);
}
ll query(int o,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return a[o];
    ll ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>=mid+1)ans+=query(rson,L,R);
    return ans;
}
void update(int o,int l,int r,int L,int R)
{
    if(l==r){
        a[o]=sqrt(a[o]);
        laz[o]=a[o];
        return;
    }
    if(L<=mid&&laz[lt]>1)update(lson,L,R);
    if(R>mid&&laz[rt]>1)update(rson,L,R);
    a[o]=a[lt]+a[rt];
    laz[o]=max(laz[lt],laz[rt]);
}
inline void read(int & x)
{
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
int n,m;
int main()
{
    int Case=0;
    while(~scanf("%d",&n))
    {
        printf("Case #%d:\n",++Case);
        for(int i=1;i<=n;i++) scanf("%lld",&wt[i]);
        build(1,1,n);
        scanf("%d",&m);
        while(m--)
        {
            int opt,x,y;
            scanf("%d %d %d",&opt,&x,&y);
            if(x>y) swap(x,y);
            if(!opt) update(1,1,n,x,y);
            else printf("%lld\n",query(1,1,n,x,y));
        }
        puts("");
    }
    return 0;
}