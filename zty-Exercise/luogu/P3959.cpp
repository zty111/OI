#include <bits/stdc++.h>
using namespace std;
const int inf = 6e5;
int n, m, e[15][15], dis[15][15], Log[4100];
int f[15][4100], g[4100], v[15], p[15], Ref[4100];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            e[i][j] = inf;
    for(int i = 1; i <= m; i++) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        u--; v--;
        e[u][v] = e[v][u] = min(e[u][v], d);
    }
    for(int i = 0; i < n; i++) Log[1 << i] = i;
    memset(f, 0x3f, sizeof(f));
    for(int i = 0; i < n; i++) f[0][1 << i] = 0; // 起点
    for(int i = 0; i < n; i++)
        for(int x = 0; x < (1 << n); x++){
            int tot = 0;
            for(int u = 0; u < n; u++) if(!(x & (1 << u))){
                v[tot] = inf;
                p[tot] = 1 << u;
                for(int j = x; j; j -= j & -j){
                    int V = Log[j & -j];
                    v[tot] = min(v[tot], e[u][V] * (i + 1));
                }
                tot++;
            }
            for(int j = 1; j < (1 << tot); j++) {
                g[j] = g[j - (j & -j)] + v[Log[j & -j]];
                Ref[j] = Ref[j - (j & -j)] | p[Log[j & -j]];
                f[i + 1][x | Ref[j]] = min(f[i + 1][x | Ref[j]], f[i][x] + g[j]);
            }
        }
    int ans = 0x3f3f3f3f;
    for(int i = 0; i <= n; i++)ans = min(ans, f[i][(1 << n) - 1]);
    printf("%d\n", ans);
    return 0;
}