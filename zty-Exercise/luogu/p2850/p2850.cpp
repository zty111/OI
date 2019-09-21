#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
vector<Edge>edges;
vector<int>G[maxn];
void add_edge(int u,int v,int d){
    edges.push_back(Edge(u,v,d));
    int mm=edges.size();
    G[u].push_back(mm-1);
}
bool vis[maxn];
int d[maxn],cnt[maxn];
bool spfa(int n){
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    queue<int>Q;
    Q.push(1);d[1]=0;vis[1]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop();vis[u]=0;
        for(int i=0;i<G[u].size();i++){
            Edge & e=edges[G[u][i]];
            if(d[e.to]>d[u]+e.dist){
                d[e.to]=d[u]+e.dist;
                if(!vis[e.to]){Q.push(e.to);vis[e.to]=1;
                if(++cnt[e.to]>n)return true;}
            }
        }
    }
    return false;
}
int main(){
    int f=read();
    while(f--){
        int n=read(),m=read(),w=read();
        edges.clear();
        for(int i=0;i<=n;i++)G[i].clear();
        for(int i=1;i<=m;i++){
            int s=read(),e=read(),t=read();
            add_edge(s,e,t);
            add_edge(e,s,t);
        }
        for(int i=1;i<=w;i++){
            int s=read(),e=read(),t=read();
            add_edge(s,e,-t);
        }
        if(spfa(n))puts("YES");
        else puts("NO");
    }
    return 0;
}