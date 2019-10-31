#include<cstdio>
#include<cstring>
using namespace std;
int SG[300][300];
int game(int n,int m){
    if(SG[n][m]!=-1)return SG[n][m];
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n-i;i++)
        vis[game(i,m)^game(n-i,m)]=1;
    for(int i=2;i<=m-i;i++)
        vis[game(n,i)^game(n,m-i)]=1;
    for(int i=0;;i++)
        if(vis[i]==0)
            return SG[n][m]=i;
}
int main(){
    int n,m;
    memset(SG,-1,sizeof(SG));
    SG[2][2]=SG[2][3]=SG[3][2]=0;
    while(scanf("%d %d",&n,&m)==2){
        int ans=game(n,m);
        if(ans>0)puts("WIN");
        else puts("LOSE");
    }
    return 0;
}