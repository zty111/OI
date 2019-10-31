#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    char static buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
const int N = 500100;
int h[N], nxt[N << 1], to[N << 1], cnt;
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int dep[N], f[N], siz[N], son[N], top[N];
void dfs1(int u, int fa, int deep) {
    dep[u] = deep;
    f[u] = fa;
    siz[u] = 1;
    int maxson = -1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u, deep + 1);
        if(maxson < siz[v]) maxson = siz[v], son[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u, int topf) {
    top[u] = topf;
    if(!son[u]) return;
    dfs2(son[u], topf);
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u] || v == son[u]) continue;
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
int n, m;
int main() {
    n = read(); m = read();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for(int i = 1; i <= m; i++) {
        int a = read(), b = read(), c = read();
        int lca1 = lca(a, b), lca2 = lca(a, c), lca3 = lca(b, c);
        int ans1;
        if(lca1 != lca2) {
            if(dep[lca1] > dep[lca2]) ans1 = lca1;
            else ans1 = lca2;
        } else {
            if(dep[lca1] > dep[lca3]) ans1 = lca1;
            else ans1 = lca3;
        }
        int ans2 = dep[a] + dep[b] + dep[c] - dep[lca1] - dep[lca2] - dep[lca3];
        printf("%d %d\n",ans1, ans2);
    }
    return 0;
}