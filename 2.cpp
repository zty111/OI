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
int c[N], nxt[N], h[N], to[N], cnt, r[N], d[N], siz[N];
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; to[cnt] = v; h[u] = cnt;
}
bool cmp(int a, int b) {
    return d[a] + siz[b] * 2 > d[b] + siz[a] * 2;
}
int tim, tot;
void dfs(int u, int fa) {
    if(u != 1) d[u] = c[u];
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs(v, u);
    }
    tot = 0;
    for(int i = h[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        r[++tot] = v;
    }
    sort(r+1, r+1+tot, cmp);
    for(int i = 1; i <= tot; i++) {
        int v = r[i];
        d[u] = max(d[u], d[v] + siz[u] * 2 + 1);
        siz[u] += siz[v] + 1;
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
    ans = c[1] + 2 * (n - 1);
    dfs(1, 0);
    printf("%d\n", max(d[1], ans));
    return 0;
}