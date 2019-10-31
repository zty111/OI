#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
struct Mat {
    int m[2][2];
    void init() {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                m[i][j] = -inf;
    }
}a[N << 2], val[N];
Mat Mul(Mat A, Mat B) {
    Mat C; C.init();
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                C.m[i][j] = max(C.m[i][j], A.m[i][k] + B.m[k][j]);
    return C;
}
int h[N], to[N << 1], nxt[N << 1], cnt, wt[N];
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int dep[N], son[N], siz[N], f[N], ncnt, id[N], top[N], b[N], ed[N];
void dfs1(int u, int fa, int deep) {
    int maxson = -1;
    f[u] = fa;
    siz[u] = 1;
    dep[u] = deep;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u, deep + 1);
        siz[u] += siz[v];
        if(siz[v] > maxson) maxson = siz[v], son[u] = v;
    }
}
void dfs2(int u, int topf) {
    id[u] = ++ncnt;
    b[ncnt] = u;
    top[u] = topf;
    ed[topf] = ncnt;
    if(!son[u]) return;
    dfs2(son[u], topf);
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int ldp[N][2], dp[N][2];
void dfs3(int u) {
    ldp[u][1] = wt[u];
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u] || v == son[u])continue;
        dfs3(v);
        ldp[u][0] += max(dp[v][1], dp[v][0]);
        ldp[u][1] += dp[v][0];
    }
    dp[u][0] += ldp[u][0];
    dp[u][1] += ldp[u][1];
    if(!son[u]) return;
    dfs3(son[u]);
    dp[u][0] += max(dp[son[u]][0], dp[son[u]][1]);
    dp[u][1] += dp[son[u]][0];
}
#define mid ((r + l) >> 1)
#define rt (o << 1 | 1)
#define lt (o << 1)
#define rson rt, mid + 1, r
#define lson lt, l, mid
void build(int o, int l, int r) {
    if(l == r) {
        val[b[l]].m[0][0] = ldp[b[l]][0]; val[b[l]].m[0][1] = ldp[b[l]][0];
        val[b[l]].m[1][0] = ldp[b[l]][1]; val[b[l]].m[1][1] = -inf;
        a[o] = val[b[l]];
        return;
    }
    build(lson); build(rson);
    a[o] = Mul(a[lt], a[rt]);
}
Mat query(int o, int l, int r, int L, int R) {
    if(l >= L && r <= R) return a[o];
    if(mid < L) return query(rson, L, R);
    if(mid + 1 > R) return query(lson, L, R);
    return Mul(query(lson, L, R), query(rson, L, R));
}
void update(int o, int l, int r, int wh) {
    if(l == r && l == wh) {
        a[o] = val[b[wh]];
        return;
    }
    if(mid >= wh) update(lson, wh);
    else update(rson, wh);
    a[o] = Mul(a[lt], a[rt]);
}
int n, m;
void change(int u, int w) {
    val[u].m[1][0] += w - wt[u];
    wt[u] = w;
    while(u != 0) {
        int now = top[u];
        Mat la = query(1, 1, n, id[now], ed[now]);
        update(1, 1, n, id[u]);
        Mat nw = query(1, 1, n, id[now], ed[now]);
        u = f[now];
        val[u].m[0][0] += max(nw.m[0][0], nw.m[1][0]) - max(la.m[0][0], la.m[1][0]);
        val[u].m[0][1] = val[u].m[0][0];
        val[u].m[1][0] += nw.m[0][0] - la.m[0][0];
    }
}
int main() {
    n = read(); m = read();
    for(int i = 1; i <= n; i++) wt[i] = read();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    dfs3(1);
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int u = read(), w = read();
        change(u, w);
        Mat ans = query(1, 1, n, id[1], ed[1]);
        printf("%d\n", max(ans.m[0][0], ans.m[1][0]));
    }
    return 0;
}