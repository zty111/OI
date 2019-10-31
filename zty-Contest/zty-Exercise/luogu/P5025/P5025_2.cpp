#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define int long long
const int N = 500010;
const int mod = 1e9 + 7;
int h[N*2], nxt[N*24], to[N*24], cnt, id[N], x[N], r[N], n, nod;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; to[cnt] = v; h[u] = cnt;
}
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt, l, mid
#define rson rt, mid+1, r
void build(int o, int l, int r) {
    if(l == r) {
        id[l] = o;
        nod = max(nod, o);
        return;
    }
    build(lson); build(rson);
    add_edge(o, lt); add_edge(o, rt);
}
void link(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        if(id[v] == o) return;
        add_edge(id[v], o);
        return;
    }
    if(L <= mid) link(lson, L, R, v);
    if(R > mid) link(rson, L, R, v);
}
int num, cnum, dfn[N*4], low[N*4], scc[N*4], s[N*4], top, ins[N*4];
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
            scc[v]=cnum;
        }while(u!=v);
    }
}
int w[N*4], deg[N*4], Cnt, To[N*8], Nxt[N*8], H[N*4], f[N*4];
map<pair<int, int>, int> vis;
void add(int u, int v) {
    Cnt++; To[Cnt] = v; Nxt[Cnt] = H[u]; H[u] = Cnt;
}
signed main() {
    n = read();
    for(int i = 1; i <= n; i++) x[i] = read(), r[i] = read();
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        int ll = lower_bound(x+1, x+1+n, x[i] - r[i]) - x;
        int rr = upper_bound(x+1, x+1+n, x[i] + r[i]) - x - 1;
        link(1, 1, n, ll, rr, i);
    }

    for(int i = 1; i <= nod; i++) if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; i++) w[scc[id[i]]]++;

    for(int x = 1; x <= nod; x++)
        for(int i = h[x]; i; i = nxt[i]) {
            int y = to[i];
            if(scc[x] == scc[y]) continue;
            pair<int, int> t = make_pair(scc[y], scc[x]);
            if(vis[t] == 1) continue;
            vis[t] = 1;
            add(scc[y], scc[x]);
            deg[scc[x]]++;
        }
    
    queue<int>q;   
    for(int i = 1; i <= cnum; i++) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        f[x] += w[x];
        for(int i = H[x]; i; i = Nxt[i]) {
            int y = To[i];
            f[y] += f[x];
            deg[y]--;
            if(!deg[y]) q.push(y);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + i * f[scc[id[i]]] % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}