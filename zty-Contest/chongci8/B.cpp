#include<bits/stdc++.h>
using namespace std;
int a[1<<13];
bool vis[1<<13];
bool dfs(int u,int step,int n)
{
    if(vis[u])return 0;
    vis[u]=1;
    a[step]=u&1;
    if(step==n-1)return 1;
    if(dfs((u<<1)&(n-1),step+1,n))return 1;
    if(dfs((u<<1)&(n-1)|1,step+1,n))return 1;
    vis[u]=0;
    return 0;
}
int main()
{
    int n,k;
    cin>>k;
    n=1<<k;
    dfs(0,0,n);
    printf("%d ",n);
    for(int i=1;i<k;i++)printf("0");
    for(int i=0;i<n-k+1;i++)printf("%d",a[i]);
    printf("\n");
}