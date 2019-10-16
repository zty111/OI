#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 65;
int n, m, f[N][N][N], d[N][N];
int main() {
    scanf("%d %d", &n, &m);
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f[u][v][0] = 1;
        d[u][v] = 1;
    }
    for(int i = 1; i <= 64; i++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                for(int k = 1; k <= n; k++)
                    if(f[u][k][i-1] && f[k][v][i-1])
                        f[u][v][i] = 1, d[u][v] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    printf("%d\n", d[1][n]);
    return 0;
}