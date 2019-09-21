#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int d[N],vis[N],a[N][N],n;
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(x==0||d[j]<d[x]))x=j;
        vis[x]=1;
        for(int y=1;y<=n;y++)
            d[y]=min(d[y],d[x]+a[x][y]);
    }
}
