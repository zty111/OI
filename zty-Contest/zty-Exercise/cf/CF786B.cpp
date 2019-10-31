#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int n, m, Q;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
const int N = 200010;
int d[N * 4],vis[N * 4],e[N * 20],to[N * 20],h[N * 4],nxt[N * 20],cnt;
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
const int inf = 0x3f3f3f3f3f3f3f3f;
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(d[v]>d[u]+e[i]){
                d[v]=d[u]+e[i];
                q.push(make_pair(d[v],v));
            }
        }
    }
}
#define mid ((l+r)>>1)
int lt[N * 4], rt[N * 4], cn, id[N], id_2[N];
void build1(int o, int l, int r) {
    if(l == r) {
        id[l] = o;
        return;
    }
    lt[o] = ++cn; build1(lt[o], l, mid);
    rt[o] = ++cn; build1(rt[o], mid+1, r);
    add_edge(o, lt[o], 0);
    add_edge(o, rt[o], 0);
}
void link1(int o, int l, int r, int L, int R, int v, int w) {
    if(L <= l && r <= R) {
        add_edge(id[v], o, w);
        return;
    }
    if(L <= mid) link1(lt[o], l, mid, L, R, v, w);
    if(R > mid) link1(rt[o], mid + 1, r, L, R, v, w);
}
void build2(int o, int l, int r) {
    if(l == r) {
        id_2[l] = o;
        return;
    }
    lt[o] = ++cn; build2(lt[o], l, mid);
    rt[o] = ++cn; build2(rt[o], mid+1, r);
    add_edge(lt[o], o, 0);
    add_edge(rt[o], o, 0);
}
void link2(int o, int l, int r, int L, int R, int v, int w) {
    if(L <= l && r <= R) {
        add_edge(o, id_2[v], w);
        return;
    }
    if(L <= mid) link2(lt[o], l, mid, L, R, v, w);
    if(R > mid) link2(rt[o], mid+1, r, L, R, v, w);
}
int rt1, rt2;
signed main() {
    n = read(); Q = read(); m = read();
    cn = 1; rt1 = cn;
    build1(rt1, 1, n); 
    cn++; rt2 = cn;
    build2(rt2, 1, n);
    for(int i = 1; i <= Q; i++) {
        int opt = read();
        if(opt == 1) {
            int v = read(), u = read(), w = read();
            add_edge(id[v], id_2[u], w);
        } else if(opt == 2) {
            int v = read(), l = read(), r = read(), w = read();
            link1(rt1, 1, n, l, r, v, w);
        } else {
            int v = read(), l = read(), r = read(), w = read();
            link2(rt2, 1, n, l, r, v, w);
        }
    }
    for(int i = 1; i <= n; i++) add_edge(id[i], id_2[i], 0), add_edge(id_2[i], id[i], 0);
    dijkstra(id[m]);
    for(int i = 1; i <= n; i++) printf("%lld ", d[id_2[i]] >= inf ? -1ll : d[id_2[i]]);
    return 0;
}