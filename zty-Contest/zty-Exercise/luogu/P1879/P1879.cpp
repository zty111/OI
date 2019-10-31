#include<bits/stdc++.h>
using namespace std;
int n,m,dp[13][1<<12],vis[13][13],ok[1<<12],v[13];
const int mod = 100000000;
long long ans;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&vis[i][j]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            v[i]=(v[i]<<1)+vis[i][j];
    for(int s=0;s<(1<<n);s++)
        if(((s&(s>>1)))==0&&(s&(s<<1))==0)
            ok[s]=1;
    dp[0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<(1<<n);j++)if(ok[j]&&(j&v[i])==j)
            for(int k=0;k<(1<<n);k++)if((k&j)==0)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
    for(int j=0;j<(1<<n);j++)ans=(ans+dp[m][j])%mod;
    printf("%lld\n",ans);
    return 0;
}