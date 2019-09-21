#include<cstdio>
#include<iostream>
using namespace std;
const int N =50010;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
#define mid ((l+r)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define len r-l+1;
#define lt (o<<1)
#define rt (o<<1|1)
int sum[N<<2],lmax[N<<2],rmax[N<<2],laz[N<<2],lenn[N<<2];
void build(int o,int l,int r){
    sum[o]=lmax[o]=rmax[o]=lenn[o]=len;
    if(l==r)return;
    build(lson);build(rson);
}
void pushdown(int o){
    if(!laz[o])return;
    laz[lt]=laz[rt]=laz[o];
    sum[lt]=lmax[lt]=rmax[lt]=(laz[lt]==2)?lenn[lt]:0;
    sum[rt]=lmax[rt]=rmax[rt]=(laz[rt]==2)?lenn[rt]:0;
    laz[o]=0;
}
void pushup(int o){
    if(sum[lt]==lenn[lt])lmax[o]=lenn[lt]+lmax[rt];
    else lmax[o]=lmax[lt];
    if(sum[rt]==lenn[rt])rmax[o]=lenn[rt]+rmax[lt];
    else rmax[o]=rmax[rt];
    sum[o]=max(max(sum[lt],sum[rt]),rmax[lt]+lmax[rt]);
}
void change(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        if(k==1)sum[o]=lmax[o]=rmax[o]=0;
        else sum[o]=lmax[o]=rmax[o]=lenn[o]; 
        laz[o]=k;
        return;
    }
    pushdown(o);
    if(L<=mid)change(lson,L,R,k);
    if(R>=mid+1)change(rson,L,R,k);
    pushup(o);
}
int query(int o,int l,int r,int k){
    if(l==r)return l;
    pushdown(o);
    if(sum[lt]>=k)return query(lson,k);
    if(rmax[lt]+lmax[rt]>=k)return mid-rmax[lt]+1;
    else return query(rson,k);    
}
int n,m;
int main(){
    n=read();m=read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt=read(),x=read();
        if(opt==1){
            if(sum[1]>=x){
                int ans=query(1,1,n,x);
                printf("%d\n",ans);
                change(1,1,n,ans,ans+x-1,1);
            }
            else printf("0\n");
        }
        else{
            int y=read();
            change(1,1,n,x,x+y-1,2);
        }
    }
    return 0;
}