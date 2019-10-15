#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, K, a[N][2],sum[N][2], dp[N][N][11], f[N][11];
void solve1() {
    for(int i = 1; i <= n; i++) sum[i][0] = sum[i-1][0] + a[i][0];
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= K; k++) {
            f[i][k] = f[i-1][k];
            for(int j = 0; j <= i - 1; j++)
                f[i][k] = max(f[i][k], f[j][k-1] + sum[i][0] - sum[j][0]);
        }
    printf("%d\n", f[n][K]);
}
void solve2() {
    for(int i = 1; i <= n; i++) sum[i][0] = sum[i-1][0] + a[i][0], sum[i][1] = sum[i-1][1] + a[i][1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= K; k++) {
                dp[i][j][k] = max(dp[i][j-1][k], dp[i-1][j][k]);
                for(int d = 0; d <= i-1; d++)
                    dp[i][j][k] = max(dp[i][j][k], dp[d][j][k-1] + sum[i][0] - sum[d][0]);
                for(int d = 0; d <= j-1; d++)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][d][k-1] + sum[j][1] - sum[d][1]);
                if(i == j)
                    for(int d = 0; d <= i-1; d++)
                        dp[i][j][k] = max(dp[i][j][k], dp[d][d][k-1] + sum[i][1] + sum[i][0] - sum[d][1] - sum[d][0]);
            }
    printf("%d\n", dp[n][n][K]);
}
int main() {
    scanf("%d %d %d", &n, &m, &K);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j - 1]);
    if(m == 1) solve1();
    else solve2();
    return 0;
}