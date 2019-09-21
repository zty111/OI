#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 500010;
int h[N], to[N], nxt[N], cnt, in[N];
void add_edge(int u, int v) {
    ++cnt; to[cnt] = v; nxt[cnt] = h[u]; h[u] = cnt;
}
int c[N], ccnt, dfn[N], low[N], num, s[N], top, ins[N];
void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    s[++top] = u;
    ins[u] = 1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        ccnt++;
        int v;
        do {
            v = s[top--];
            c[v] = ccnt;
            ins[v] = 0;
        } while(v != u);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a != b) add_edge(a,b);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    for(int u = 1; u <= n; u++)
        for(int i = h[u]; i; i = nxt[i]){
            int v = to[i];
            if(c[v] != c[u]) in[c[v]]++;
        }
    int ans = 0;
    for(int i = 1; i <= ccnt; i++)
        if(!in[i]) ans++;
    printf("%d\n", ans);
    return 0;
}