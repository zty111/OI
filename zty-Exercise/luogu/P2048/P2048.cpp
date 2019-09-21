// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
const int maxn = 500010;
int n,m,cnt=0,l,r;
int a[maxn],b[maxn],T[maxn];
int sum[maxn<<5],L[maxn<<5],R[maxn<<5];
long long ans;
int build(int l,int r)
{
    int rt=++cnt;
    sum[rt]=0;
    if(l<r)
    {
        L[rt]=build(l,mid);
        R[rt]=build(mid+1,r);
    }
    return rt;
}
int update(int pre,int l,int r,int x)
{
    int rt=++cnt;
    L[rt]=L[pre];R[rt]=R[pre];sum[rt]=sum[pre]+1;
    if(l<r)
    {
        if(x<=mid)L[rt]=update(L[pre],l,mid,x);
        else R[rt]=update(R[pre],mid+1,r,x);
    }
    return rt;
}
int query(int u,int v,int l,int r,int k)
{
    if(l>=r)return l;
    int x=sum[L[v]]-sum[L[u]];
    if(x>=k)return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-x);
}
void read(int & x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
struct rec{
    int x,st,k;
};
bool operator <(rec a,rec b){return a.x<b.x;}
priority_queue<rec>q;
int main()
{
    read(n);read(m);read(l);read(r);
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
        a[i]+=a[i-1];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int siz=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+siz+1,a[i])-b;
    T[0]=build(1,n);
    for(int i=1;i<=n;i++)T[i]=update(T[i-1],1,n,a[i]);
    for(int i=1;i<=n;i++){
        int LL=i+l-1,RR=min(n,i+r-1);
        if(LL>n)continue;
        int x=b[query(T[LL-1],T[RR],1,n,1)]-b[a[i-1]];
        q.push((rec){x,i,1});
    }
    for(int i=1;i<=m;i++){
        rec c=q.top();q.pop();
        cout<<i<<' '<<c.x<<endl;
        ans+=(long long)c.x;
        int LL=c.st+l-1,RR=min(c.st+r-1,n);
        if((LL<=n)&&(RR-LL+1>c.k)){
            int x=b[query(T[LL-1],T[RR],1,n,c.k+1)]-b[a[c.st-1]];
            q.push((rec){x,c.st,c.k+1});
        }
    }
    printf("%lld\n",ans);
    return 0;
}