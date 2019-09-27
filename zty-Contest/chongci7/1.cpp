#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100010], b[100010], sum, ans;
bool vis[100010];
ll prim[100010], p;
int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
    for(int i = 2; i <= 100000; i++) {
        if(!vis[i])prim[++p] = i;
        for(int j = i; j <= n; j += i) {
            vis[j] = 1;
        }
    }
    prim[++p] = sum;
    ans = 1e18;
    for(ll i = 1; i <= p; i++) {
        ll x = prim[i];
        if(sum % x)continue;
        for(int i = 1; i <= n; i++) b[i] = a[i] % x;
        ll Ans = 0, now = 0;
        sort(b + 1, b + 1 + n);
        int l = 1, r = n;
        while(l <= r) {
            while(!b[r])r--;
            if(r < l)break;
            now += b[l];
            Ans += b[l];
            l++;
            while(b[r] + now >= x) {
                now -= x - b[r];
                r--;
            }
        }
        ans = min(ans, Ans);
    }
    printf("%lld\n", ans);
    return 0;
}