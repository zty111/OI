#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
const int N = 100010;
int n, m, a[N], cnt, nxt[N << 1], to[N << 1], h[N];
inline void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int dep[N], f[N], siz[N], son[N], id[N], ncnt, top[N], w[N];
void dfs1(int u, int fa, int deep) {
    dep[u] = deep;
    siz[u] = 1;
    f[u] = fa;
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
    id[u] = ++ncnt;
    w[ncnt] = a[u];
    if(!son[u]) return;
    dfs2(son[u], topf);
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == son[u] || v == f[u]) continue;
        dfs2(v, v);
    }
}
#define mid ((l + r) >> 1)
#define lt (o << 1)
#define rt (o << 1 | 1)
#define lson lt, l, mid
#define rson rt, mid + 1, r
int col[N << 2], lc[N << 2], rc[N << 2], sum[N << 2], ans1, ans2, LC, RC;
inline void pushup(int o) {
    sum[o] = sum[lt] + sum[rt];
    if(rc[lt] == lc[rt]) sum[o]--;
    lc[o] = lc[lt]; rc[o] = rc[rt];
}
inline void pushdown(int o) {
    sum[lt] = sum[rt] = 1;
    col[lt] = col[rt] = col[o];
    lc[lt] = rc[lt] = col[o];
    lc[rt] = rc[rt] = col[o];
    col[o] = 0;
}
void build(int o, int l, int r) {
    if(l == r) {
        lc[o] = rc[o] = w[l];
        sum[o] = 1;
        return;
    }
    build(lson); build(rson);
    pushup(o);
}
void update(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        sum[o] = 1;
        lc[o] = rc[o] = col[o] = v;
        return;
    }
    if(col[o]) pushdown(o);
    if(L <= mid) update(lson, L, R, v);
    if(R > mid) update(rson, L, R, v);
    pushup(o);
}
int query(int o, int l, int r, int L, int R) {
    if(r == R) RC = rc[o];
    if(l == L) LC = lc[o];
    if(L <= l && r <= R) {
        return sum[o];
    }
    if(col[o]) pushdown(o);
    int ans = 0;
    if(L <= mid) ans += query(lson, L, R);
    if(R > mid) ans += query(rson, L, R);
    if(L <= mid && R > mid && rc[lt] == lc[rt]) ans--;
    return ans;
}
void updRange(int x, int y, int v) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], v);
        x = f[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y], v);
}
int qRange(int x, int y) {
    ans1 = ans2 = -1;
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y), swap(ans1, ans2);
        ans += query(1, 1, n, id[top[x]], id[x]);
        if(ans1 == RC) ans--;
        ans1 = LC;
        x = f[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y), swap(ans1, ans2);
    ans += query(1, 1, n, id[x], id[y]);
    if(ans1 == LC) ans--;
    if(ans2 == RC) ans--;
    return ans;
}
int main() {
    n = read(); m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        char ch = nc();
        while(ch != 'C' && ch != 'Q') ch = nc();
        if(ch == 'C') {
            int a = read(), b = read(), c = read();
            updRange(a, b, c);
        } else {
            int a = read(), b = read();
            printf("%d\n", qRange(a, b));
        }
    }
    return 0;
}