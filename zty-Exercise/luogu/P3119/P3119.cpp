#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 200010;
const int inf = 0x3f3f3f3f;
int n, m;
int h[N],nxt[N],to[N],cnt;
void add_edge(int u,int v){
    cnt++;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int dfn[N],low[N],num,s[N],ins[N],cnum,top,c[N],dp[N];
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
            dp[cnum]++;
        }while(u!=v);
    }
}
int to_c[N][2],h_c[N][2],nxt_c[N][2],cnt_c, in[N][2], e[N][2];
void add_c(int u, int v){
    cnt_c++;
    to_c[cnt_c][0]=v;nxt_c[cnt_c][0]=h_c[u][0];h_c[u][0]=cnt_c; in[v][0]++; e[cnt_c][0] = dp[v];
    to_c[cnt_c][1]=u;nxt_c[cnt_c][1]=h_c[v][1];h_c[v][1]=cnt_c; in[u][1]++; e[cnt_c][1] = dp[u];
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
int dis[N][2];
int main(){
    int n = read(), m = read();
    for(int i = 1; i <= m; i++) {
        int x = read(), y = read();
        add_edge(x, y);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    for(int u = 1; u <= n; u++)
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(c[v] == c[u]) continue;
            add_c(c[u], c[v]);
        }
    memset(dis, -0x3f, sizeof(dis));
    for(int d = 0; d <= 1; d++) {
        dis[c[1]][d] = 0;
        queue<int> q;
        for(int i = 1; i <= cnum; i++) if(!in[i][d]) q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = h_c[u][d]; i; i = nxt_c[i][d]) {
                int v = to_c[i][d];
                dis[v][d] = max(dis[v][d], dis[u][d] + e[i][d]);
                in[v][d]--;
                if(!in[v][d]) q.push(v);
            }
        }
    }
    int ans = 0;
    for(int u = 1; u <= n; u++)
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(c[v] == c[u]) continue;
            //if(dis[c[v]][0] > 0 && dis[c[u]][1] > 0) 
            ans = max(dis[c[v]][0] + dis[c[u]][1] + dp[c[1]], ans);
        }
    printf("%d\n", ans);
    return 0;
}