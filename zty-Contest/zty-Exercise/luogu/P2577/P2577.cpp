#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, a[N], b[N], dp[N][N * N], sum[N], r[N];
bool cmp(int A, int B) {
    return b[A] > b[B];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d %d", &a[i], &b[i]), r[i] = i;
    sort(r+1, r+1+n, cmp);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[r[i]];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= sum[i]; j++) {
            if(j - a[r[i]] >= 0) dp[i][j] = min(dp[i][j], max(j + b[r[i]], dp[i-1][j-a[r[i]]]));
            dp[i][j] = min(dp[i][j], max(dp[i-1][j], sum[i] - j + b[r[i]]));
        }
    int ans = 0x3f3f3f3f;
    for(int j = 0; j <= sum[n]; j++) {
        ans = min(ans, dp[n][j]);
    }
    printf("%d\n", ans);
    return 0;
}