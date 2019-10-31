#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n,m,a[N],d[N],now[N],ans,b[N],bl[N],br[N];
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
bool check(int x){
    for(int i=1;i<=n;i++){
        now[i]=d[i];
    }
    for(int i=1;i<=x;i++){
        now[bl[i]]-=b[i];
        now[br[i]+1]+=b[i];
    }
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+=now[i];
        if(ret<0)return true;
    }
    return false;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
    for(int i=1;i<=m;i++){
        b[i]=read();bl[i]=read();br[i]=read();
    }
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(ans==0)printf("%d\n",ans);
    else{
        printf("-1\n");
        printf("%d\n",ans);
    }
    return 0;
}
