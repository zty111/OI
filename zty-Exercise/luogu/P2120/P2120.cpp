#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000100;
#define int long long
int n, sump[N], sum[N], head, tail, x[N], p[N], c[N], dp[N], q[N];
inline double slope(int i, int j) {
    return (double)(dp[j] + sum[j] - dp[i] - sum[i]) / (sump[j] - sump[i]);
}
signed main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &p[i], &c[i]);
        sump[i] = sump[i-1] + p[i];
        sum[i] = sum[i-1] + x[i] * p[i];
    }
    for(int i = 1; i <= n; i++) {
        while(head < tail && slope(q[head], q[head + 1]) < x[i]) head++;
        int j = q[head];
        dp[i] = dp[j] + x[i] * (sump[i] - sump[j]) - sum[i] + sum[j] + c[i];
        while(head < tail && slope(q[tail - 1], q[tail]) > slope(q[tail], i)) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", dp[n]);
    return 0;
}