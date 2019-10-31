#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,ans;
long long a[40],b[40];
void dfs(int num,long long now,int cnt){
    if(cnt>=ans)return;
    if(now==(1LL<<n)-1){ans=cnt;return;}
    if(num>n)return;
    if(a[n-num+1]==0){
        dfs(num+1,now,cnt);
        for(int i=num+1;i<=n;i++)if((a[i]>>num)&1LL)a[i]^=1LL;
        dfs(num+1,now^b[num],cnt+1);
        for(int i=num+1;i<=n;i++)if((a[i]>>num)&1LL)a[i]^=1LL;
    }
    else{
        if((a[n-num+1]&1LL)==1LL)dfs(num+1,now^b[num],cnt+1);
        else dfs(num+1,now,cnt);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)a[i]|=(1LL<<i),a[i]|=1LL;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&p,&q);
        a[p]|=(1LL<<q);
        a[q]|=(1LL<<p);
    }
    for(int i=1;i<=n;i++)b[i]=(a[i]>>1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            if(a[j]>a[i])swap(a[j],a[i]);
        if(a[i]==0)break;
        for(int k=n;k;k--)
            if((a[i]>>k)&1LL){
                for(int j=1;j<=n;j++)
                    if(i!=j&&((a[j]>>k)&1LL))a[j]^=a[i];
                break;
            }
    }
    ans=n;
    dfs(1,0LL,0);
    printf("%d\n",ans);
    return 0;
} 