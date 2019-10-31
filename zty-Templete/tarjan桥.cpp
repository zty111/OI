#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100010;
int dfn[N], low[N], h[N], nxt[N], to[N], cnt = 1, num, bridge[N];
void add_edge(int u, int v) {
    ++cnt; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++num;
    for(int i = h[x]; i; i = nxt[i]) {
        int y = to[i];
        if(!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if(low[y] > dfn[x])
                bridge[i] = bridge[i^1] = true;
        } else if(i != (in_edge ^ 1))
            low[x] = min(low[x], dfn[y]);
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
int main() {
    int n = read(), m = read();
    for(int i = 1; i <= m; i++) {
        int x = read(), y = read();
        add_edge(x, y); add_edge(y, x);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i, 0);
    for(int i = 2; i < cnt; i += 2)
        if(bridge[i]) printf("%d %d\n", to[i^1], to[i]);
    return 0;
}