#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char nc(){
    static char buf[200000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,200000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    register char ch=nc();register int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
struct qus{
    int l,r,id,pos;
}a[50010];
inline bool cmp(qus A,qus B){
    if(A.pos==B.pos){
        if(A.pos%2==1)
            return A.r<B.r;
        else return A.r>B.r;
    }
    return A.pos<B.pos;
}
int n,m,c[50010],R,L=1,cnt[50010];
ll ans[50010][2],Ans;
inline void add(int x){
    Ans+=2*cnt[c[x]];cnt[c[x]]++;
}
inline void del(int x){
    cnt[c[x]]--;Ans-=2*cnt[c[x]];
}
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    n=read();m=read();
    int lpos=sqrt(n);
    for(register int i=1;i<=n;i++){
        c[i]=read();
    }
    for(register int i=1;i<=m;i++){
        a[i].l=read();
        a[i].r=read();
        a[i].pos=a[i].l/lpos;
        a[i].id=i;
    }
    sort(a+1,a+1+m,cmp);
    for(register int i=1;i<=m;i++){
        if(a[i].l==a[i].r){
            ans[a[i].id][1]=1;continue;
        }
        while(L<a[i].l)del(L++);
        while(L>a[i].l)add(--L);
        while(R>a[i].r)del(R--);
        while(R<a[i].r)add(++R);
        ll len=1ll*(R-L+1)*(R-L);
        ll d=gcd(len,Ans);
        ans[a[i].id][0]=Ans/d;
        ans[a[i].id][1]=len/d;
    }
    for(register int i=1;i<=m;i++){
        printf("%lld/%lld\n",ans[i][0],ans[i][1]);
    }
    return 0;
}