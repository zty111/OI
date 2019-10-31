#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
vector<Edge>edges;
vector<int>G[N];
int out[N],deg[N];
double F[N];
int n,m,a,b,c;
void add_edge(int u,int v,int d){
    edges.push_back(Edge(u,v,d));
    int mm=edges.size();
    G[u].push_back(mm-1);
}
queue<int>q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        add_edge(b,a,c);
        out[a]++;deg[a]++;
    }
    q.push(n);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<G[u].size();i++){
            Edge & e=edges[G[u][i]];
            out[e.to]--;
            F[e.to]+=(F[u]+e.dist)/deg[e.to];
            if(out[e.to]==0)q.push(e.to);
        }
    }
    printf("%.2f",F[1]);
    return 0;
}