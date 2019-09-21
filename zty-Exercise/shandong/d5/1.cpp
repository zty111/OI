#include<bits/stdc++.h>
using namespace std;
int n,m,d[200010],vis[200010];
void bfs(){
    memset(vis,0,sizeof(vis));
    queue<int>q;
    d[n]=0;vis[n]=1;
    q.push(n);
    while(!q.empty()){
        int u=q.front();q.pop();
        int to=u+1;
        if(to>=1&&to<=200000&&!vis[to])
            d[to]=d[u]+1,vis[to]=1,q.push(to);
        to=u-1;
        if(to>=1&&to<=200000&&!vis[to])
            d[to]=d[u]+1,vis[to]=1,q.push(to);
        to=(u<<1);
        if(to>=1&&to<=200000&&!vis[to])
            d[to]=d[u]+1,vis[to]=1,q.push(to);
        if(vis[m])return;
    }
}
int main(){
    while(scanf("%d%d",&n,&m)){
        bfs();
        printf("%d\n",d[m]);
    }
    return 0;
}