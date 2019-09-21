#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,100000,stdin), p1 == p2)? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >='0' && ch <='9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 200010;
int h[N], nxt[N], cnt, e[N], to[N];
void add_edge(int u, int v, int w) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; e[cnt] = w; to[cnt] = v;
}
int dis[N], ins[N];
const int inf = 2147483647;
int n, m, s;
void spfa(int s){
    for(int i = 1; i <= n; i++) dis[i] = inf;
    dis[s] = 0;
    deque<int> q;
    ins[s] = 1;
    q.push_front(s);
    long long qsz = 1, sum = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        if(dis[u] * qsz > sum){
            q.push_back(u);
            continue;
        }
        sum -= dis[u];
        --qsz;
        ins[u] = 0;
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[u] + e[i] < dis[v]) {
                dis[v] = dis[u] + e[i];
                if(!ins[v]){
                    if(!q.empty() && dis[v] < dis[q.front()])
                        q.push_front(v);
                    else q.push_back(v);
                    ins[v] = 1;
                    sum += dis[v];
                    ++qsz;
                }
            }
        }
    }
}
int main() {
    n = read(); m = read(); s = read();
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add_edge(u, v, w);
    }
    spfa(s);
    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}