#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10005;
char s[N];
int p = -1, h[N], nxt[N], to[N], cnt, vis[N];
void add_edge(int u, int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int lt[N], rt[N], num = 1;
void build(int o) {
    p++; vis[o] = 1;
    if(s[p] == '0') return;
    if(s[p] == '1') {
        lt[o] = ++num;
        add_edge(o, lt[o]);
        build(lt[o]);
        return;
    }
    if(s[p] == '2') {
        rt[o] = ++num;
        add_edge(o, rt[o]);
        build(rt[o]);
        return;
    }
    if(s[p] == '3') {
        lt[o] = ++num;
        rt[o] = ++num;
        add_edge(o, lt[o]);
        add_edge(o, rt[o]);
        build(lt[o]);
        build(rt[o]);
    }
}
int siz[N];
void dfs(int o) {
    siz[o] = 1;
    for(int i = h[o]; i; i = nxt[i]) {
        int v = to[i];
        dfs(v);
        siz[o] += siz[v];
    }
}
int ans1 = 0, ans2 = 0;
int main() {
    scanf("%s", s);
    build(1);
    int o = 1;
    dfs(1);
    while(vis[o]) {
        ans1 = max(ans1, 2 * siz[rt[o]]);
        o = lt[o];
    }
    o = 1;
    while(vis[o]) {
        ans2 = max(ans2, 2 * siz[lt[o]]);
        o = rt[o];
    }
    ans1 = min(ans1, ans2) + 1;
    printf("%d\n", ans1);
    return 0;
}