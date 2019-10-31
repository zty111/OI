#include <bits/stdc++.h>
using namespace std;
const int N = 5010010;
int h[N], to[N], nxt[N], cnt, e[N];
void add_edge(int u, int v, int d) {
    cnt++; nxt[cnt] = h[u]; to[cnt] = v; e[cnt] = d; h[u] = cnt;
}
int s, t, n, m, k, d[N], vis[N];
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii> >q;
void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(d[v] > d[u] + e[i]) {
                d[v] = d[u] + e[i];
                q.push(make_pair(d[v], v));
            }
        }
    }
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int main() {
    n = read(); m = read(); k = read(); s = 1; t = n;
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), d = read();
        add_edge(u, v, d); add_edge(v, u, d);
        for(int j = 1; j <= k; j++) {
            add_edge(v + j * n, u + j * n, d);
            add_edge(u + j * n, v + j * n, d);
            add_edge(u + (j-1) * n, v + j * n, 0);
            add_edge(v + (j-1) * n, u + j * n, 0);
        }
    }
    for(int i = 1; i <= k; i++)
        add_edge(t + (i-1) * n, t + i * n, 0);
    dijkstra();
    printf("%d\n", d[n * k + t]);
    return 0;
}