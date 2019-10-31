#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,m;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
inline int g_int(){
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    return ch-48;
}
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
#define len (r-l+1)
int a[N<<2],laz[N<<2];
void build(int o,int l,int r){
    if(l==r){a[o]=g_int();return;}
    build(lson);build(rson);
    a[o]=a[lt]+a[rt];
}
void pushdown(int o,int lenn){
    laz[lt]^=1;laz[rt]^=1;
    a[lt]=(lenn-(lenn>>1))-a[lt];
    a[rt]=(lenn>>1)-a[rt];
    laz[o]=0;
}
void update(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R){a[o]=len-a[o];laz[o]^=1;return;}
    if(laz[o])pushdown(o,len);
    if(L<=mid)update(lson,L,R);
    if(R>=mid+1)update(rson,L,R);
    a[o]=a[lt]+a[rt];
}
int query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R)return a[o];
    if(laz[o])pushdown(o,len);
    int ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>=mid+1)ans+=query(rson,L,R);
    return ans;
}
int main(){
    n=read();m=read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int p=read(),l=read(),r=read();
        if(p==0)update(1,1,n,l,r);
        else printf("%d\n",query(1,1,n,l,r));
    }
    return 0;
}