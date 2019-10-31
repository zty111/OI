#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> g, b;
int num;
string s1, s2;
const int N = 100010;
int h[N], nxt[N], to[N], cnt;
void add_edge(int u, int v){
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int dfn[N], low[N], numm, c[N], s[N], ins[N], top, cnum;
void tarjan(int u) {
    dfn[u] = low[u] = ++numm;
    s[++top] = u; ins[u] = 1;
    for(int i = h[u]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        int v; ++cnum;
        do {
            v = s[top--];
            ins[v] = 0;
            c[v] = cnum;
        } while(u != v);
    }
}
int main() {
    int n, m;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>s1>>s2;
        g[s1] = ++num;
        b[s2] = ++num;
        add_edge(g[s1], b[s2]);
    }
    cin>>m;
    for(int i = 1; i <= m; i++) {
        cin>>s1>>s2;
        add_edge(b[s2], g[s1]);
    }
    for(int i = 1; i <= num; i++) if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= num; i += 2) {
        if(c[i] == c[i+1]) cout<<"Unsafe"<<endl;
        else cout<<"Safe"<<endl;
    }
    return 0;
}