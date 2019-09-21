#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
const int N = 100010;
int d[N],vis[N],e[N],to[N],h[N],nxt[N],cnt;
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(d[v]>d[u]+e[i]){
                d[v]=d[u]+e[i];
                q.push(make_pair(d[v],v));
            }
        }
    }
}