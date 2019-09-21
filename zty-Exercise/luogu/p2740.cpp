#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int INF = 0x7fffffff;
void read(int & x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
int n,m,s,t;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
vector<Edge>edges;
vector<int>G[maxn];
void add_edge(int from,int to,int cap)
{
    edges.push_back(Edge(from,to,cap,0));
    edges.push_back(Edge(to,from,0,0));
    int mm=edges.size();
    G[from].push_back(mm-2);
    G[to].push_back(mm-1);
}
bool vis[maxn];
int d[maxn];
bool BFS()
{
    memset(vis,0,sizeof(vis));
    d[s]=0;vis[s]=1;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            Edge & e=edges[G[u][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                d[e.to]=d[u]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}
int cur[maxn];
int DFS(int u,int a)
{
    int flow=0,f=0;
    if(a==0||u==t)return a;
    for(int & i=cur[u];i<G[u].size();i++)
    {
        Edge & e=edges[G[u][i]];
        if(d[e.to]==d[u]+1&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
        {
            flow+=f;
            a-=f;
            e.flow+=f;
            edges[G[u][i]^1].flow-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int Maxflow()
{
    int flow=0;
    while(BFS())
    {
        memset(cur,0,sizeof(cur));
        flow+=DFS(s,INF);
    }
    return flow;
}
int main()
{
    read(n);read(m);
    s=1;t=m;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        read(u);read(v);read(w);
        add_edge(u,v,w);
    }
    printf("%d",Maxflow());
    return 0;
}
