#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,v[210][210],d[210],vis[210];
void bfs(){
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(a);
    d[a]=0;vis[a]=1;
    while(q.size()){
        int u=q.front();q.pop();
        for(int i=1;i<=n;i++)if(!vis[i]&&v[u][i]){
            vis[i]=1;
            d[i]=d[u]+1;
            if(i==b)return;
            q.push(i);
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        if(i+k<=n)v[i][i+k]=1;
        if(i-k>=1)v[i][i-k]=1;
    }
    bfs();
    printf("%d\n",d[b]);
    return 0;
}