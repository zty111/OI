#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, p, a[N][N], dp[N], c[N];
int main() {
    memset(dp, -0x3f, sizeof(dp));
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    dp[0] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            int ans = dp[i - 1] - c[j];
            for(int k = 0; k < p && i + k <= m; k++) {
                int now = j + k > n ? j + k - n : j + k;
                ans += a[now][i + k];
                dp[i + k] = dp[i + k] > ans ? dp[i + k] : ans;
            }
        }
    printf("%d\n", dp[m]);
    return 0;
}