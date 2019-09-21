#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int n,m,k,e,d;
int a[N][N],dp[N][N];
bool vis[N][N],val[N];
long long f[N],cost[N][N];
int main(){
    scanf("%d %d %d %d",&n,&m,&k,&e);
    for(int i=1;i<=e;i++){
        int x,y,d;
        scanf("%d %d %d",&x,&y,&d);
        a[x][y]=d;a[y][x]=d;
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++){
        int p,x,y;
        scanf("%d %d %d",&p,&x,&y);
        for(int j=x;j<=y;j++)
            vis[p][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            memset(dp,0x3f,sizeof(dp));
            memset(val,0,sizeof(val));
            for(int p=1;p<=m;p++){
                for(int ii=i;ii<=j;ii++)
                    if(vis[p][ii])val[p]=1;
                dp[p][p]=0;
            }
            for(int o=1;o<=m;o++)if(!val[o])
                for(int x=1;x<=m;x++)if(!val[x])
                    for(int y=1;y<=m;y++)if(!val[y]&&a[o][y])
                        dp[x][y]=min(dp[x][y],dp[x][o]+a[o][y]);
            cost[i][j]=1ll*dp[1][m]*(j-i+1);
            //cout<<i<<' '<<j<<' '<<dp[1][m]<<' '<<cost[i][j]<<endl;
        }
    for(int i=1;i<=n;i++){
        f[i]=cost[1][i];
        for(int j=1;j<=i;j++){
            f[i]=min(f[i],f[j]+cost[j+1][i]+k);
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}