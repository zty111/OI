#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int inf = 0x3f3f3f3f;
int T, n, m ,k ,p;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int h[N], nxt[N], cnt, to[N], e[N];
void add_edge(int u, int v, int w) {
    cnt++; e[cnt] = w; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int H[N], Nxt[N], Cnt, To[N], E[N];
void add(int u,int v,int w) {
    Cnt++; E[Cnt] = w; Nxt[Cnt] = H[u]; H[u] = Cnt; To[Cnt] = v;
}
int ins[N], d[N];
void spfa() {
    for(int i = 1; i <= n; i++) d[i] = inf, ins[i] = 0;
    queue<int> q;
    q.push(n);
    ins[n] = 1;
    d[n] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ins[u] = 0;
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(d[u] + e[i] < d[v]) {
                d[v] = d[u] + e[i];
                if(!ins[v]){
                    ins[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int in[N][52], f[N][52];
int dfs(int u, int rest) {
    if(in[u][rest]) return -1;
    if(f[u][rest]) return f[u][rest];
    int ans = 0;
    in[u][rest] = 1;
    if(u == n) ans = 1;
    for(int i = H[u]; i; i = Nxt[i]) {
        int v = To[i];
        int det = d[v] + E[i] - d[u];
        if(rest - det >= 0){
            int w = dfs(v, rest - det);
            if(w == -1) return f[u][rest] = -1;
            ans = (ans + w) % p;
        }
    }
    in[u][rest] = 0;
    return f[u][rest] = ans;
}
void init() {
    for(int i = 1; i <= n; i++) h[i] = H[i] = 0;
    cnt = Cnt = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= k; j++)
            in[i][j] = f[i][j] = 0;
}
int main() {
    T = read();
    while(T--) {
        n = read(); m = read(); k = read(); p = read();
        init();
        for(int i = 1; i <= m; i++){
            int u = read(), v = read(), w = read();
            add_edge(v, u, w);
            add(u, v, w);
        }
        spfa();
        printf("%d\n", dfs(1, k));       
    }
    return 0;
}