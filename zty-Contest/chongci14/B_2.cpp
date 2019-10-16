#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 300010;
typedef long long ll;
typedef pair<int,int> pii;
int n, p, x, y, d[N];
map<pii,int> g;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int main() {
    n = read(); p = read();
    for(int i = 1; i <= n; i++) {
        x = read(); y = read();
        if(x > y) swap(x, y);
        d[x]++; d[y]++; g[pii(x,y)]++;
    }
    ll ans = 0;
    for(auto it:g) {
        int x = it.first.first, y = it.first.second;
        if(d[x] + d[y] >= p && d[x] + d[y] - it.second < p) --ans;
    }
    sort(d+1, d+1+n);
    int now = n;
    for(int i = 1; i <= n; i++) {
        while(now > i && d[now] + d[i] >= p) ++ans;
        ans += n - max(i, now);
    }
    printf("%lld\n", ans);
}