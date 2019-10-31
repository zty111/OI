#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N][N], dp[N][N], pre[N][N];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= m - n + 1; i++) {
        dp[1][i] = a[1][i]; pre[1][i] = i;
    }
    for(int i = 2; i <= n; i++)
        for(int j = i; j <= m - n + i; j++) {
            int maxx = dp[i - 1][i - 1], prej = i - 1;
            for(int k = i; k <= j - 1; k++) {
                maxx = max(maxx, dp[i - 1][k]);
                prej = k;
            }
            dp[i][j] = maxx + a[i][j];
            pre[i][j] = prej;
        }
    
    return 0;
}