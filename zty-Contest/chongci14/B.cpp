#include <cstdio>
using namespace std;
const int N = 300010;
int n, p, x[N], y[N], cnt, vis[N];
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
long long ans;
int main() {
    n = read(); p = read();
    if(p == 0) {
        for(int i = 1; i < n; i++) ans += n;
        printf("%lld\n", ans);
        return 0;
    }
    if(p == 1) {
        for(int i = 1; i <= 2 * n; i++) {
            int X = read();
            if(!vis[X]) cnt++;
            vis[X] = 1;
        }
        int cnt2 = n - cnt;
        ans = 1ll * cnt * cnt2 + 1ll * cnt * (cnt - 1) / 2;
        printf("%lld\n", ans);
        return 0;
    }
    for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++) {
            cnt = 0;
            for(int k = 1; k <= n; k++) 
                if(x[k] == i || x[k] == j || y[k] == i || y[k] == j) cnt++;
            if(cnt >= p) ans++;
        }
    printf("%lld\n", ans);
    return 0;
}