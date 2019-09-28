#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int inf = 0x3f3f3f3f;
int h[N], nxt[N << 1], to[N << 1], cnt;
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
int f[N], dep[N], top[N], siz[N], son[N], id[N], ncnt, pos[N], ed[N];
void dfs1(int u, int fa, int deep) {
    f[u] = fa;
    int maxson = -1;
    siz[u] = 1;
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
    id[u] = ++ncnt;
    pos[ncnt] = u;
    ed[topf] = ncnt;
    if(!son[u]) return;
    dfs2(son[u], topf);
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int dp[N][2], ldp[N][2], w[N], n, m;
void dfs3(int u) {
    ldp[u][1] += w[u];
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u] || v == son[u]) continue;
        dfs3(v);
        ldp[u][0] += max(dp[v][0], dp[u][1]);
        ldp[u][1] += dp[u][0];
    }
    dp[u][0] += ldp[u][0];
    dp[u][1] += ldp[u][1];
    if(!son[u]) return;
    dfs3(son[u]);
    dp[u][0] += max(dp[son[u]][0], dp[son[u]][1]);
    dp[u][1] += dp[son[u]][0];
}
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
#define mid ((l + r) >> 1)
#define lt (o << 1)
#define rt (o << 1 | 1)
#define lson lt, l, mid
#define rson rt, mid + 1, r
void build(int o, int l, int r) {
    if(l == r) {
        val[pos[l]].m[0][0] = ldp[pos[l]][0];
        val[pos[l]].m[0][1] = ldp[pos[l]][0];
        val[pos[l]].m[1][0] = ldp[pos[l]][1];
        val[pos[l]].m[1][1] = -inf;
        a[o] = val[pos[l]];
        return;
    }
    build(lson); build(rson);
    a[o] = Mul(a[lt], a[rt]);
}
void update(int o, int l, int r, int wh) {
    if(l == r && l == wh) {
        a[o] = val[pos[wh]];
        return;
    }
    if(mid >= wh) update(lson, wh);
    else update(rson, wh);
    a[o] = Mul(a[lt], a[rt]);
}
Mat query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) return a[o];
    if(L > mid) return query(rson, L, R);
    if(R < mid + 1) return query(lson, L, R);
    return Mul(query(lson, L, R), query(rson, L, R));
}
void change(int u,int ww) {
    val[u].m[1][0] += ww - w[u];
    w[u] = ww;
    while(u != 0) {
        int now = top[u];
        Mat la = query(1, 1, n, id[now], ed[now]);
        update(1, 1, n, id[u]);
        Mat nw = query(1, 1, n, id[now], ed[now]);
        u = f[now];
        val[u].m[0][0] += max(nw.m[0][0], nw.m[0][1]) - max(la.m[0][0], la.m[0][1]);
        val[u].m[0][1] = val[u].m[0][0];
        val[u].m[1][0] += nw.m[0][0] -la.m[0][0];
    }
}
long long tot;
void solve(int a, int b, int x, int y) {
    if(x) change(a, inf); else change(a, -inf);
    if(y) change(b, inf); else change(b, -inf);
    Mat ans = query(1, 1, n, id[1], ed[1]);
    tot += ((x ^ 1) + (y ^ 1)) * inf;
    long long Ans = tot - max(ans.m[0][0], ans.m[1][0]);
    tot -= ((x ^ 1) + (y ^ 1)) * inf;
    if(!x) change(a, inf); else change(a, -inf);
    if(!y) change(b, inf); else change(b, -inf);
    if(Ans > inf) printf("-1\n");
    else printf("%lld\n", Ans);
}
char opt[10];
int main() {
    n = read(); m = read(); scanf("%s", opt);
    for(int i = 1; i <= n; i++) w[i] = read(), tot += w[i];
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= m; i++) {
        int a = read(), b = read(), x = read(), y = read();
        solve(a, b, x, y);       
    }
    return 0;
}