#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 200010;
int n,m;
int h[N],nxt[N],e[N],to[N],cnt;
void add_edge(int u,int v){
    cnt++;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int dfn[N],low[N],num,s[N],ins[N],cnum,top,c[N],dp[N][2];
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
            dp[cnum][0]++;
        }while(u!=v);
    }
}
int to_c[N],h_c[N],nxt_c[N],cnt_c, in[N];
void add_c(int u,int v){
    cnt_c++;to_c[cnt_c]=v;nxt_c[cnt_c]=h_c[u];h_c[u]=cnt_c; in[v]++;
}
inline char nc(){
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1==p2 && (p2= (p1=buf) + fread(buf,1,100000,stdin), p1==p2)? EOF : *p1++;
}
inline int read(){
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = (x<<3) + (x<<1) + ch - 48, ch = nc();
    return x * f;
}
int val[N], x[N], y[N];
void dfs(int u, int d) {
    val[u] = d;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(!val[v]) dfs(v, d);
    }
}
int main(){
    int n = read(), m = read();
    for(int i = 1; i <= m; i++) {
        x[i] = read(), y[i] = read();
        add_edge(x[i], y[i]);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    dfs(1, 1);
    cnt = 0; memset(h, 0, sizeof(h));
    for(int i = 1; i <= m; i++) add_edge(y[i], x[i]);
    dfs(1, 2); val[1] = 3;
    cnt = 0; memset(h, 0, sizeof(h));
    for(int i = 1; i <= m; i++) add_edge(x[i], y[i]);
    for(int u = 1; u <= n; u++)
        for(int i = h[u]; i; i = nxt[i]){
            int v = to[i];
            if(c[u] == c[v])continue;
            if(c[v] == c[1]) add_c(c[u], cnum + 1);
            else if(val[u] == 2 && val[v] == 1) add_c(c[v], c[u]);
            else if(val[u] != 0 && val[v] != 0) add_c(c[u], c[v]);
        }
    queue<int> q;
    int ans = 0;
    for(int i = 1; i <= cnt; i++) if(!in[i])q.push(i), dp[i][1] = dp[i][0];
    printf("%d\n", ans);
    return 0;
}