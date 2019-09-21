#include<bits/stdc++.h>
using namespace std;
int vis[25],a[25][25],c[25],n,ans,g[25],path[25],I,maxn;
void dfs(int u,int sum){
    int flag=0;
    vis[u]=1;
    for(int i=1;i<=n;i++)if(!vis[i]&&a[u][i]){
        flag=1;
        path[u]=i;
        dfs(i,sum+c[i]);
        path[u]=0;
    }
    vis[u]=0;
    if(!flag)
        if(ans<sum){
            ans=sum;maxn=I;
            for(int i=1;i<=n;i++)g[i]=path[i];
        }
}
void print(int u){
    printf("%d ",u);
    if(g[u])print(g[u]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(I=1;I<=n;I++)
        dfs(I,c[I]);
    print(maxn);printf("\n");
    printf("%d\n",ans);
    return 0;
}