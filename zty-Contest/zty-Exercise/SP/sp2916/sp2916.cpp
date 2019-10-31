#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 100010;
#define mid ((l+r)>>1)
#define lt o<<1
#define rt o<<1|1
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define len (r-l+1)
struct tree{
    int pre,bat,suf,sum;
    tree(){pre=0;bat=0;suf=0;sum=0;}
}a[maxn<<2],emp;
int wt[maxn];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void update(int o){
    a[o].sum=a[lt].sum+a[rt].sum;
    a[o].bat=max(a[lt].bat,a[rt].bat);
    a[o].bat=max(a[o].bat,a[lt].suf+a[rt].pre);
    a[o].pre=max(a[lt].sum+a[rt].pre,a[lt].pre);
    a[o].suf=max(a[rt].sum+a[lt].suf,a[rt].suf);
}
void build(int o,int l,int r){
    if(l==r){a[o].pre=a[o].bat=a[o].suf=a[o].sum=wt[l]=read();return;}
    build(lson);build(rson);
    update(o);
}
tree query(int o,int l,int r,int L,int R){
    if(L>R)return emp;
    if(L<=l&&r<=R)return a[o];
    if(L>mid)return query(rson,L,R);
    if(R<=mid)return query(lson,L,R);
    tree ans,A,B;
    A=query(lson,L,R);B=query(rson,L,R);
    ans.bat=max(A.bat,B.bat);
    ans.bat=max(ans.bat,A.suf+B.pre);
    ans.pre=max(A.pre,A.sum+B.pre);
    ans.sum=A.sum+B.sum;
    ans.suf=max(B.suf,B.sum+A.suf);
    return ans;
}
int main(){
    int T=read();
    while(T--){
        int n=read();
        build(1,1,n);
        int m=read();
        for(int i=1;i<=m;i++){
            int ll,lr,rl,rr;
            ll=read();lr=read();rl=read();rr=read();
            if(lr<rl){
                printf("%d\n",query(1,1,n,ll,lr).suf+query(1,1,n,lr+1,rl-1).sum+query(1,1,n,rl,rr).pre);
            }
            else{
                int ans=query(1,1,n,rl,lr).bat;
                if(ll<rl)ans=max(ans,query(1,1,n,ll,rl).suf+query(1,1,n,rl,rr).pre-wt[rl]);
                if(rr>lr)ans=max(ans,query(1,1,n,ll,lr).suf+query(1,1,n,lr,rr).pre-wt[lr]);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}