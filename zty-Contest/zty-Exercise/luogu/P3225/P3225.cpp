#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int dfn[N], low[N], h[N], nxt[N], to[N], cnt, num, cut[N], root;
void add_edge(int u, int v) {
    ++cnt; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    int flag = 0;
    for(int i = h[x]; i; i = nxt[i]) {
        int y = to[i];
        if(!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dfn[x]) {
                flag++;
                if(x != root || flag > 1) cut[x] = 1;
            }
        } else low[x] = min(low[x], dfn[y]);
    }
}
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
int now, nowcut, ans1, vis[N], kase;
long long ans2, nownum;
void dfs(int u) {
    vis[u] = now;
    nownum++;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(cut[v] && vis[v] != now) {
            nowcut++;
            vis[v] = now;
        }
        if(!vis[v]) dfs(v);
    }
}
int main() {
    while(1) {
        int m = read(), n = 0; if(m == 0) break;
        memset(h, 0, sizeof(h));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        memset(vis, 0, sizeof(vis));
        ans1 = cnt = num = now = 0; ans2 = 1;
        for(int i = 1; i <= m; i++) {
            int x = read(), y = read();
            if(x == y) continue;
            add_edge(x, y); add_edge(y, x);
            n = max(n, x); n = max(n, y);
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) root = i, tarjan(i);
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && !cut[i]) {
                ++now; nowcut = nownum = 0;
                dfs(i);
                if(nowcut == 0) {
                    ans1 += 2;
                    ans2 *= (nownum - 1) * nownum / 2;
                }
                else if(nowcut == 1) {
                    ans1++;
                    ans2 *= nownum;
                }
            }
        }
        printf("Case %d: %d %lld\n", ++kase, ans1, ans2);
    }
    return 0;
}