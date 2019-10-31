#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, ans;
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
const int N = 1000010;
int c[N], nxt[N], h[N], to[N], cnt, dis[N], r[N], d[N], siz[N];
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; to[cnt] = v; h[u] = cnt;
}
void dfs(int u, int fa) {
    siz[u] = 1;
    d[u] = c[u] + dis[u];
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
bool cmp(int a, int b) {
    return d[a] + (siz[b] - 1) * 2 > d[b] + (siz[a] - 1) * 2;
}
int tim, tot;
void dfs2(int u, int fa) {
    ans = max(ans, c[u] + tim);
    int now = tot;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        r[++tot] = v;
    }
    int now2 = tot;
    sort(r+now+1, r+1+tot, cmp);
    for(int i = now + 1; i <= now2; i++) {
        int v = r[i];
        tim++;
        dfs2(v, u);
    }
    tim++;
}
void dp(int u, int fa) {
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dp(v, u);
        d[u] = max(d[v], d[u]);
    }
}
int main() {
    n = read();
    for(int i = 1; i <= n; i++) c[i] = read();
    for(int i = 1; i < n; i++) {
        int a = read(), b = read();
        add_edge(a, b);
        add_edge(b, a);
    }
    dis[1] = 1; ans = c[1] + 2 * (n - 1);
    dfs(1, 0);
    dp(1, 0);
    dfs2(1, 0);
    printf("%d\n", ans);
    return 0;
}