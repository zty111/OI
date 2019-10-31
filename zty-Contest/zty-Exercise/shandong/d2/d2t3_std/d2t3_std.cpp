#include<bits/stdc++.h>
using namespace std;
#define int long long
int f1[1010];
int A,B,n,a[1010],sum[1010];
bool able[1010],able2[110][110];//转移是否可用
bool check1(int ba,int tar){
    memset(able,0,sizeof(able));
    memset(f1,0x3f,sizeof(f1));
    able[0]=true;f1[0]=0;
    for(int i=1;i<=n;i++)
        for(int k=i-1;k>=0;k--)
            if(able[k]&&((sum[i]-sum[k])|ba)<tar){
                able[i]=true;
                f1[i]=min(f1[i],f1[k]+1);
            }
    if(able[n]&&f1[n]<=B)return true;
    else return false;
}
bool check2(int ba,int tar){
    memset(able2,0,sizeof(able2));
    able2[0][0]=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=B;j++)
            for(int k=i-1;k>=0;k--)
                if(able2[k][j-1]&&((sum[i]-sum[k])|ba)<tar){
                    able2[i][j]=true;
                    break;
                }
    for(int i=A;i<=B;i++)
        if(able2[n][i])return true;
    return false;
}
signed main(){
    scanf("%lld%lld%lld",&n,&A,&B);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int maxans=sum[n],ans=0;
    int cnt=1;while((1LL<<(cnt-1))<maxans)cnt++;
    if(A==1){
        //case 1 O(n*n*logSUM)
        for(int i=cnt;i>=1;i--){
            int tar=ans|(1LL<<(i-1));
            if(!check1(ans,tar))
                ans+=(1LL<<(i-1));
        }
        printf("%lld\n",ans);
    }
    else{
        //case 2 O(n*n*n*logSUM)
        for(int i=cnt;i>=1;i--){
            int tar=ans|(1LL<<(i-1));
            if(!check2(ans,tar))
                ans+=(1LL<<(i-1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}