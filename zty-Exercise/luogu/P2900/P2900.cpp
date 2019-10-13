#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50010;
int n, cnt, q[N], head, tail;
long long dp[N];
struct land {
    int l, r;
}a[N], c[N];
bool cmp(land A, land B) {
    if(A.l == B.l) return A.r > B.r;
    return A.l > B.l;
}
inline double k(int i, int j) {
    return 1.0 * (dp[i] - dp[j]) / (c[j+1].l - c[i+1].l);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].l, &a[i].r);
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++)
        if(c[cnt].r < a[i].r) c[++cnt] = a[i];
    for(int i = 1; i <= cnt; i++) {
        while(head < tail && k(q[head], q[head + 1]) < c[i].r) head++;
        int j = q[head];
        dp[i] = dp[j] + 1ll * c[j + 1].l * c[i].r;
        while(head < tail && k(q[tail - 1], q[tail]) > k(q[tail - 1], i)) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", dp[cnt]);
    return 0;
}