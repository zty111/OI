#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m, g[N][N], q, c[N][N][2], sum[N][N][2], r1, c1, r2, c2;
char ch;
inline void ge() {
    ch = getchar();
    while(ch != '.' && ch != '#') ch = getchar();
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            ge();
            if(ch == '.') g[i][j] = 1;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(g[i][j] && g[i][j-1]) c[i][j][0]++;
            if(g[i][j] && g[i-1][j]) c[i][j][1]++;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k <= 1; k++)
            sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] - sum[i-1][j-1][k] + c[i][j][k];
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int ans = sum[r2][c2][0] + sum[r1 - 1][c1][0] - sum[r1 - 1][c2][0] - sum[r2][c1][0];
        ans += sum[r2][c2][1] + sum[r1][c1 - 1][1] - sum[r1][c2][1] - sum[r2][c1 - 1][1];
        printf("%d\n", ans);
    }
    return 0;
}