#include <cstdio>
#include <iostream>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 510;
int n, m, w[N], v[N], d[N], nxt[N], h[N], to[N], cnt;
inline void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int nxt_c[N], h_c[N], to_c[N], dfn[N], low[N], s[N], top, ins[N], num, c[N], cnum, in[N], val[N], we[N];
inline void add_c(int u, int v) {
    cnt++; nxt_c[cnt] = h_c[u]; h_c[u] = cnt; to_c[cnt] = v; in[v]++;
}
void tarjan(int u) {
    low[u] = dfn[u] = ++num;
    ins[u] = 1; s[++top] = u;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        int y; cnum++;
        do {
            y = s[top--];
            ins[y] = 0;
            c[y] = cnum;
            val[cnum] += v[y];
            we[cnum] += w[y];
        } while(u != y);
    }
}
int dp[N][N];
void DP(int u) {
    for(int i = we[u]; i <= m; i++) dp[u][i] = val[u];
    for(int i = h_c[u]; i; i = nxt_c[i]) {
        int v = to_c[i];
        DP(v);
        for(int j = m - we[u]; j >= 0; j--)
            for(int k = 0; k <= j; k++)
                dp[u][j + we[u]] = max(dp[u][j + we[u]], dp[u][j+we[u]-k] + dp[v][k]);
    }
}
int main() {
    n = read(); m = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    for(int i = 1; i <= n; i++) v[i] = read();
    for(int i = 1; i <= n; i++) d[i] = read();
    for(int i = 1; i <= n; i++) if(d[i]) add_edge(d[i], i);
    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    cnt = 0;
    for(int u = 1; u <= n; u++)
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(c[u] == c[v]) continue;
            add_c(c[u], c[v]);
        }
    for(int i = 1; i <= cnum; i++) if(!in[i]) add_c(0, i);
    DP(0);
    printf("%d\n", dp[0][m]);
    return 0;
}