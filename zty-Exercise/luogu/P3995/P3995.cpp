#include <cstdio>
#include <iostream>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
const int N = 100010;
int n, q, u, v;
int son[N], siz[N], dep[N], top[N], f[N], c[N], ans[N];
int h[N], to[N<<1], nxt[N<<1], cnt;
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
void dfs1(int u, int fa, int deep) {
    siz[u] = 1;
    f[u] = fa;
    dep[u] = deep;
    int maxson = -1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u, deep + 1);
        siz[u] += siz[v];
        if(siz[v] > maxson) maxson = siz[v], son[u] = v;
    }
}
void dfs2(int u, int topf) {
    top[u] = topf;
    if(!son[u]) return;
    dfs2(son[u], topf);
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == son[u] || v == f[u]) continue;
        dfs2(v, v);
    }
}
int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = f[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    return x;
}
void dfs(int u) {
    int maxson = -1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u]) continue;
        dfs(v);
        c[u] += c[v];
        if(c[v] >= maxson) ans[u] = v, maxson = c[v];
    }
}
int main() {
    n = read(); q = read();
    for(int i = 1; i <= n-1; i++) {
        u = read(); v = read();
        add_edge(u, v); add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for(int i = 1; i <= q; i++) {
        u = read(); v = read();
        int LCA = lca(u, v);
        if(f[u] != LCA) c[u]++, c[LCA]--;
        if(f[v] != LCA) c[v]++, c[LCA]--;
    }
    dfs(1);
    for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}