#include<bits/stdc++.h>
using namespace std;
const int mod = 9999973;
typedef long long ll;
int n,m;
ll dp[2][105][105],ans;
inline int C(int a){return a*(a-1)/2;}
int main(){
    scanf("%d%d",&n,&m);
    int o=1;dp[0][0][0]=1;
    for(int i=1;i<=n;o^=1,i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k+j<=m;k++){
                dp[o][j][k]=dp[o^1][j][k];
                if(j-1>=0)dp[o][j][k]+=dp[o^1][j-1][k]*(m-j-k+1);
                if(k-1>=0)dp[o][j][k]+=dp[o^1][j+1][k-1]*(j+1);
                if(j-2>=0)dp[o][j][k]+=dp[o^1][j-2][k]*C(m-j-k+2);
                if(k-1>=0)dp[o][j][k]+=dp[o^1][j][k-1]*j*(m-j-k+1);
                if(k-2>=0)dp[o][j][k]+=dp[o^1][j+2][k-2]*C(j+2);
                dp[o][j][k]%=mod;
            }
    for(int i=0;i<=m;i++)
        for(int j=0;j+i<=m;j++)
            ans=(ans+dp[o^1][i][j])%mod;
    printf("%lld\n",ans);
    return 0;
}