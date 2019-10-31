#include <iostream>
#include <cstdlib>
#include <cstdio>
#define int long long
#define rep(i, l, r) for(register int i = l; i <= r; i++)
#define per(i, r, l) for(register int i = r; i >= l; i--)

using namespace std;
const int N = 10010000;
int n, x[N], p[N], c[N], dp[N];
int sum[N], sump[N], h, t, Q[N];
inline int Y(int i) {
    return dp[i] + sum[i];
}
inline int X(int i) {
    return sump[i];
}
inline double slope(int j, int k) {
    return 1.0 * (Y(j) - Y(k)) / (X(j) - X(k));
}
signed main() {
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d%d%d", &x[i], &p[i], &c[i]);
        sump[i] = sump[i - 1] + p[i];
        sum[i] = sum[i - 1] + x[i] * p[i];
    }
    rep(i, 1, n) {
        while(h < t && slope(Q[h + 1], Q[h]) < x[i]) h++;
        int j = Q[h]; dp[i] = dp[j] + x[i] * (sump[i] - sump[j]) - sum[i] + sum[j] + c[i];
        while(h < t && slope(Q[t], Q[t - 1]) > slope(i, Q[t])) t--; Q[++t] = i;
        cout<<dp[i]<<endl;
    }
    printf("%lld\n", dp[n]);
    return 0;
}