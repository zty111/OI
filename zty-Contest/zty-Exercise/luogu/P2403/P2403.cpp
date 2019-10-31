#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9')  x = x * 10 + ch - 48, ch = nc();
    return x;
}
const int M = 1e6;
const int N = 3e5 + 5;
const int _N = 1e5 + 5;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cnt, nxt[M], h[N], to[M];
map<int, int>x, y;
map<pair<int, int>, int> mp;
int cx, n, R, C, inx[_N], iny[_N], ino[_N], dfn[N], low[N], c[N], num;
inline void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int nxt_c[M], h_c[M], to_c[M], s[N], ins[N], top, cnum, in[N];
inline void add_c(int u, int v) {
    cnt++; nxt_c[cnt] = h_c[u]; h_c[u] = cnt; to_c[cnt] = v; in[v]++;
}
int c_cnt[N], dp[N], ans;
void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    s[++top] = u; ins[u] = 1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        cnum++; int v;
        do {
            v = s[top--]; ins[v] = 0;
            c[v] = cnum;
            if(v <= n) c_cnt[cnum]++;
        } while(v != u);
    }
}
int main() {
    n = read(); R = read(); C = read(); cx = n;
    for(int i = 1; i <= n; i++) {
        inx[i] = read(); iny[i] = read(); ino[i] = read();
        mp[make_pair(inx[i], iny[i])] = i;
    }
    for(int i = 1; i <= n; i++) {
        int _x = inx[i], _y = iny[i], opt = ino[i];
        if(x[_x] == 0) x[_x] = ++cx;
        if(y[_y] == 0) y[_y] = ++cx;
        add_edge(x[_x], i);
        add_edge(y[_y], i);
        if(opt == 1) add_edge(i, x[_x]);
        else if(opt == 2) add_edge(i, y[_y]);
        else for(int d = 0; d < 8; d++) {
            int tox = _x + dx[d], toy = _y + dy[d];
            if(mp[make_pair(tox, toy)]) add_edge(i, mp[make_pair(tox, toy)]);
        }
    }
    for(int i = 1; i <= cx; i++) if(!dfn[i]) tarjan(i);
    cnt = 0;
    for(int u = 1; u <= cx; u++)
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(c[u] == c[v]) continue;
            add_c(c[u], c[v]);
        }
    queue<int> q;
    for(int i = 1; i <= cnum; i++) if(!in[i]) q.push(i), dp[i] = c_cnt[i], ans = max(ans, dp[i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = h_c[u]; i; i = nxt_c[i]) {
            int v = to_c[i];
            dp[v] = max(dp[v], dp[u] + c_cnt[v]);
            in[v]--;
            if(!in[v]) q.push(v), ans = max(ans, dp[v]);
        }
    }
    printf("%d\n", ans);
    return 0;
}