#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m;
int h[N],nxt[N],e[N],to[N],cnt;
void add_edge(int u,int v,int w){
    cnt++;e[cnt]=w;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int dfn[N],low[N],num,s[N],ins[N],d[N],cnum,top,c[N];
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
            c[v]=cnum;scc[cnum].push_back(v);
        }while(u!=v);
    }
}
int to_c[N],h_c[N],nxt_c[N],cnt_c;
void add_c(int u,int v){
    cnt_c++;to_c[cnt_c]=v;nxt_c[cnt_c]=h_c[u];h_c[u]=cnt_c;
}
int main(){
    for(int u=1;u<=n;u++)
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(c[u]==c[v])continue;
            add_c(c[u],c[v]);
        }
    return 0;
}