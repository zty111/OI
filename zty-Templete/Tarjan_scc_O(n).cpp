#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int e[N],to[N],nxt[N],h[N],cnt;
void add_edge(int u,int v,int w){
    ++cnt;e[cnt]=w;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int dfn[N],low[N],c[N],s[N],ins[N],top,cnum,num;
vector<int>scc[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    s[++top]=u;ins[u]=1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        cnum++;int v;
        do{
            v=s[top--];ins[v]=0;
            c[v]=cnum;
            scc[cnum].push_back(v);
        }while(v!=u);
    }
}
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    return 0;
}