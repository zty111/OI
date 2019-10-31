#include <cstdio>
#include <iostream>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 1e6;
int T, k, cnt, vis[N + 10], n;
long long prim[N];
bool check(int r) {
    return prim[r] - prim[r-k] <= n;
}
int main() {
    T = read();
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) prim[++cnt] = i;
        vis[i] = 1;
        for(int j = 1; j <= cnt; j++) {
            if(prim[j] * i > N) break;
            vis[prim[j] * i] = 1;
        }
    }
    for(int i = 1; i <= cnt; i++) prim[i] += prim[i-1];
    while(T--) {
        n = read(); k = read();
        int r = cnt, l = 1, ans = 0;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        if(ans >= k) printf("%lld\n", prim[ans] - prim[ans - k]);
        else printf("-1\n");
    }
    return 0;
}