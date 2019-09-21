#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int n,m;
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
int cnt=1,e[N],to[N],nxt[N],h[N],s,dis[N],vis[N],fa[N];
long long ans;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
void add_edge(int u,int v,int d){
    cnt++;e[cnt]=d;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(fa,0x3f,sizeof(fa));
    fa[s]=0;
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
                fa[v]=e[i];
                q.push(make_pair(dis[v],v));
            }
            else if(dis[v]==dis[u]+e[i]){
                fa[v]=min(fa[v],e[i]);
            }
        }
    }
}
signed main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u,v,d;
        u=read();v=read();d=read();
        add_edge(u,v,d);
        add_edge(v,u,d);
    }
    s=read();
    dijkstra();
    for(int i=1;i<=n;i++)ans+=fa[i];
    printf("%lld\n",ans);
    return 0;
}