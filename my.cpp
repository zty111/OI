#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
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
const int N = 1e5 + 10;
int h[N], to[N], cnt, nxt[N], in[N], cn;
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v; in[v]++;
}
int T, ans[N];
priority_queue<int> q;
int main() {
    T = read();
    while(T--) {
        cn = cnt = 0;
        memset(h, 0, sizeof(h));
        memset(in, 0, sizeof(in));
        int n = read(), m = read();
        for(int i = 1; i <= m; i++) {
            int x = read(), y = read();
            add_edge(y, x);
        }
        for(int i = 1; i <= n; i++) if(!in[i])
            q.push(i);
        while(q.size()) {
            int u = q.top(); q.pop();
            ans[++cn] = u;
            for(int i = h[u]; i; i = nxt[i]) {
                int v = to[i];
                in[v]--;
                if(!in[v]) q.push(v);
            }
        }
        if(cn == n) for(int i = n; i >= 1; i--) printf("%d ", ans[i]);
        else printf("Impossible!");
        printf("\n");
    }
    return 0;
}