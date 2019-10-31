#include<bits/stdc++.h>
using namespace std;
int n,xa,xb,ya,yb;
typedef long long ll;
const int N = 3000000;
struct line{
    int x1,x2,y,c;
}A[N];
int rk[N],val[N],cnt[N];
ll ans=0,lenn[N];
bool cmp(line aaa,line bbb){
    return aaa.y<bbb.y;
}
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
#define len (r-l+1)
void pushup(int o,int l,int r){
    if(cnt[o])lenn[o]=val[r+1]-val[l];
    else if(l==r)lenn[o]=0;
    else lenn[o]=lenn[lt]+lenn[rt];
}
void update(int o,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        cnt[o]+=k;
        pushup(o,l,r);
        return;
    }
    if(L<=mid)update(lson,L,R,k);
    if(R>=mid+1)update(rson,L,R,k);
    pushup(o,l,r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        A[i*2-1].x1=xa;A[i*2-1].x2=xb;A[i*2-1].y=ya;A[i*2-1].c=1;
        A[i*2].x1=xa;A[i*2].x2=xb;A[i*2].y=yb;A[i*2].c=-1;
        rk[i*2-1]=xa;rk[i*2]=xb;
    }
    sort(rk+1,rk+2*n);
    int m=unique(rk+1,rk+2*n+1)-rk-1;
    for(int i=1;i<=2*n;i++){
        int pos1=lower_bound(rk+1,rk+m+1,A[i].x1)-rk;
        int pos2=lower_bound(rk+1,rk+1+m,A[i].x2)-rk;
        val[pos1]=A[i].x1;
        val[pos2]=A[i].x2;
        A[i].x1=pos1;
        A[i].x2=pos2;
    }
    sort(A+1,A+1+2*n,cmp);
    for(int i=1;i<=2*n;i++){
        update(1,1,m,A[i].x1,A[i].x2-1,A[i].c);
        ans+=lenn[1]*(A[i+1].y-A[i].y);
    }
    printf("%lld\n",ans);
    return 0;
}