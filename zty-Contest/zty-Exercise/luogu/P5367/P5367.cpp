#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int mod = 998244353;
int n, c[N], Ans, fac[N];
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
inline void add(int x, int i) {
    for(;x <= n;x += x & -x) c[x] += i;
}
inline int ask(int x) {
    int ans = 0;
    for(;x;x -= x & -x) ans += c[x];
    return ans;
}
int main() {
    n = read();
    fac[0] = 1;
    for(int i = 1; i < n; i++)
        fac[i] = 1ll * fac[i-1] * i % mod;
    for(int i = 1; i <= n; i++) {
        int x = read();
        Ans = (Ans + (x - 1ll * ask(x) -1) * fac[n-i] % mod) % mod;
        add(x, 1);
    }
    printf("%d\n", Ans + 1);
    return 0;
}