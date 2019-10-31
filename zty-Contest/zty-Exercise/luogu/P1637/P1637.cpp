#include<bits/stdc++.h>
using namespace std;
const int N = 30010;
int a[N],w[N],n,b[N],c[N],m;
void add(int x,int i){
    for(;x<=m;x+=x&-x)a[x]+=i;
}
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=a[x];
    return ans;
}
int query(int x){
    return lower_bound(c+1,c+1+m,x)-c;
}
long long ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]),c[i]=w[i];
    sort(c+1,c+1+n);
    m=unique(c+1,c+1+n)-(c+1);
    for(int i=1;i<=n;i++){
        b[i]=ask(query(w[i])-1);
        add(query(w[i]),1);
    }
    memset(a,0,sizeof(a));
    for(int i=n;i>=1;i--){
        int now=n-i-ask(query(w[i]));
        ans+=now*b[i];
        add(query(w[i]),1);
    }
    printf("%lld\n",ans);
    return 0;
}