#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt, nxt[100], h[100], to[100];
void add_edge(int u,int v) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v;
}
int num[10], vis[10][10];
int check() {
    for(int i = 1; i <= 6; i++)
        for(int j = i; j <= 6; j++)
            vis[i][j] = 0;
    int ans = 0;
    for(int u = 1; u <= n; u++) {
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(!vis[num[u]][num[v]]) {
                vis[num[u]][num[v]] = 1;
                ans++;
            }
        }
    }
    return ans;
}
int Ans;
void solve() {
    int mx = 1, st = 1;
    for(int i = 1; i <= n; i++) mx *= 6;
    for(int i = 1; i < mx; i++) {
        int now = i;
        for(int u = 1; u <= n; u++) {
            num[u] = now % 6;
            now /= 6;
            if(num[u] == 0) num[u] = 6;
        }
        Ans = max(Ans, check());
    }
}
int main() {
    memset(vis,1,sizeof(vis));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    solve();
    printf("%d\n", Ans);   
    return 0;
}