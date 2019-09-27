#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
ll n, m, ans, Ans, a[N], b[N];
int T;
int main() {
    scanf("%d", &T);
    while(T--){
    Ans = 0;
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll mxline = m / n;
    for(ll i = 1; i <= mxline; i++) {
        ans = (n * i + 1ll) * (n * i) / 2ll;
        ll mileft = 1ll << 60;
        for(int j = 1; j <= n; j++){
            a[j] -= i * n - n + j;
            mileft = min(mileft, a[j]);
        }
        if(mileft < 0)break;
        ll h = min(i, mileft / (m - i * n));
        ans += n * h * (m - i * n);
        ll use = h * (m - i * n);
        for(int j = 1; j <= n; j++) b[j] = a[j] - use;
        mileft = m - i * n;
        for(int j = i - h; j >= i - h - 1 && j; j--) {
            for(int k = n; k; k--) {
                mileft = min(b[k], mileft);
                ans += mileft;
                b[k] -= mileft;
                if(mileft == 0)break;
            }
        }
        Ans = max(Ans, ans);
    }
    printf("%lld\n", Ans);
    }
    return 0;
}