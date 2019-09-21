#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf =0x3f3f3f3f3f3f3f3f;
int dp[2][1010][1010],n,A,B,o,p[1010],sum[1010],ans=inf;
signed main(){
    memset(dp,0x3f,sizeof(dp));
    scanf("%lld%lld%lld",&n,&A,&B);
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+p[i];
    dp[1][0][0]=0;
    for(int i=1;i<=n;i++){
        dp[o][0][0]=0;
        for(int k=1;k<=min(i,B);k++){
            int minn=inf;
            for(int j=0;j<i;j++){
                dp[o][j][k]=dp[o^1][j][k];
                minn=min(minn,dp[o^1][j][k-1]|(sum[i]-sum[j]));
            }
            dp[o][i][k]=minn;
        }
        o^=1;
    }
    for(int k=0;k<=B;k++)
        for(int j=0;j<=n;j++)
            dp[o^1][j][k]|=sum[n]-sum[j];
    for(int k=A-1;k<=B-1;k++)
        for(int j=k;j<n;j++)
            ans=min(ans,dp[o^1][j][k]);
    for(int k=A;k<=B;k++)
        ans=min(ans,dp[o^1][n][k]);
    printf("%lld\n",ans);
    return 0;
}