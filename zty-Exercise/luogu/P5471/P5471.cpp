#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
const int N = 100010;
int dis[N],vis[N],e[N],to[N],h[N],nxt[N],cnt;
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(dis[v]>dis[u]+e[i]){
                dis[v]=dis[u]+e[i];
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int n, m, w, H, p, t, l, r, d, u, x[N], y[N];
int main() {
    n = read(); m = read(); w = read(); H = read();
    for(int i = 1; i <= n; i++) {
        x[i] = read();
        y[i] = read();
    }
    for(int i = 1; i <= m; i++) {
        p = read(); t = read(); l = read(); r = read(); d = read(); u = read();
        for(int v = 1; v <= n; v++)
            if(x[v] >= l && x[v] <= r && y[v] >= d && y[v] <= u) add_edge(p, v, t);
    }
    dijkstra(1);
    for(int i = 2; i <= n; i++) printf("%d\n", dis[i]);
    return 0;
}