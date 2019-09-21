#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 200010;
typedef long long ll;
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt,l,mid
#define rson rt,mid+1,r
const ll INF = (1LL<<63)-2;
ll c[maxn<<2];
ll query(int o,int l,int r,int L,int R){
    //cout<<"l"<<l<<" "<<"r"<<r<<endl;
    if(L<=l&&r<=R)return c[o];
    ll ans=-INF;
    if(L<=mid)ans=max(ans,query(lson,L,R));
    if(R>=mid+1)ans=max(ans,query(rson,L,R));
    return ans;
}
void add(int o,int l,int r,int x,ll k){
    if(l==x&&r==x){c[o]=k;return;}
    if(x<=mid)add(lson,x,k);
    if(x>=mid+1)add(rson,x,k);
    c[o]=max(c[lt],c[rt]);
}
int main(){
    int n,m,p=0;
    ll t=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*4;i++)c[i]=-INF;
    for(int i=1;i<=n;i++){
        ll k;char ch[2];
        scanf("%s %lld",ch,&k);
        if(ch[0]=='A'){
            ll use=(k+t)%m;
            add(1,1,n,++p,use);
           // cout<<"p"<<p<<endl;
        }
        else{
            t=query(1,1,n,p-k+1,p)%m;
           // cout<<"now"<<p-k+1<<endl;
            printf("%lld\n",t);
        }
    }
    return 0;
}
