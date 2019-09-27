#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int cnt, to[N], h[N], nxt[N];
void add_edge(int u, int v) {
    cnt++; to[cnt] = v; nxt[cnt] = h[u]; h[u] = cnt;
}
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >='0' && ch <='9') x = (x<<3) + (x<<1) + ch - 48, ch = nc();
    return x;
}
int son[N], siz[N];
void dfs1(int u, int fa) {
    siz[u] = 1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]])
            son[u] = v;
    }    
}
int col[N], num[N], top, vis[N];
long long sum[N], ans[N];
void upd(int u, int fa, int val) {
    sum[num[col[u]]] -= col[u]; // sum记录个数为num的颜色总节点值
    num[col[u]] += val; // 多了（少了）一个节点
    sum[num[col[u]]] += col[u];
    if(sum[top+1]) ++top; // top是目前最多的颜色总和
    if(!sum[top]) --top;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v != fa && !vis[v]) upd(v, u, val);
    }
}
void dfs2(int u, int fa, int keep) {
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa || v == son[u]) continue;
        dfs2(v, u, 0); //统计轻节点，不保留
    }
    if(son[u]) 
        dfs2(son[u], u, 1), vis[son[u]] = 1; //统计重节点，保留，之后无需访问
    upd(u, fa, 1);
    vis[son[u]] = 0;
    ans[u] = sum[top]; // 统计答案
    if(!keep) upd(u, fa, -1); // 不保留的删除
}
int n;
int main() {
    n = read();
    for(int i = 1; i <= n; i++) col[i] = read();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0 ,1);
    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
