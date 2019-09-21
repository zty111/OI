#include<cstdio>
using namespace std;
const int N = 10000;
int c[N],n,a[N],h[N];
void add(int x,int k){
    for(;x<=n;x+=x&-x)c[x]+=k;
}
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=c[x];
    return ans;
}
int query(int x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(ask(mid)<x)l=mid+1;
        else r=mid;
    }return l;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)add(i,1);
    for(int i=n;i>=1;i--){
        h[i]=query(a[i]+1);
        add(h[i],-1);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",h[i]);
    }
    return 0;
}