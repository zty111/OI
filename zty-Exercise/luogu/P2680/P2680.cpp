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
const int N = 300010;
int n, m, a, b, t, x, y;
int h[N], nxt[N << 1], to[N << 1], e[N << 1], cnt, pre[N];
inline void add_edge(int u, int v, int w) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v; e[cnt] = w;
}
int f[N], dep[N], siz[N], son[N], top[N], dis[N], mxpath, st[N], ed[N], z[N], dist[N];
void dfs1(int u, int fa, int deep) {
    dep[u] = deep;
    f[u] = fa;
    siz[u] = 1;
    int maxson = -1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dis[v] = dis[u] + e[i];
        pre[v] = e[i];
        dfs1(v, u, deep + 1);
        if(siz[v] > maxson) maxson = siz[v], son[u] = v;
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
int sum[N], flag, num;
int dfs(int u, int tot, int mx) {
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == f[u]) continue;
        sum[u] += dfs(v, tot, mx);
    }
    if(sum[u] >= tot && pre[u] >= mx)
        flag = 1;
    return sum[u];
}
bool check(int lim) {
    memset(sum, 0, sizeof(sum));
    flag = 0; num = 0;
    for(int i = 1; i <= m; i++)
        if(dist[i] > lim) {
            sum[st[i]]++;
            sum[ed[i]]++;
            sum[z[i]] -= 2;
            num++;
        }
    if(num == 0) return 1;
    dfs(1, num, mxpath - lim);
    return flag;
}
int main() {
    n = read(); m = read();
    for(int i = 1; i < n; i++) {
        a = read(); b = read(); t = read();
        add_edge(a, b, t);
        add_edge(b, a, t);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for(int i = 1; i <= m; i++) {
        x = read(); y = read();
        z[i] = lca(x, y);
        dist[i] = dis[x] + dis[y] - 2 * dis[z[i]];
        st[i] = x; ed[i] = y;
        mxpath = max(mxpath, dist[i]);
    }
    int l = 1, r = mxpath, ans = mxpath;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}