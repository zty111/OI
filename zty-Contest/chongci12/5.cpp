#include <bits/stdc++.h>
using namespace std;
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
const int N = 200010;
int c[N], n, m, a[N], pos[N], tot, ans[N], x = 1;
inline void add(int x) {
    for(; x <= n; x += x & -x) c[x]++;
}
inline int sum(int x) {
    int ans = 0;
    for(; x; x -= x & -x) ans += c[x];
    return ans;
}
int cnt, nxt[N << 4], num[N << 4], h[N];
inline void add(int i, int j) {
    num[++cnt] = j; nxt[cnt] = h[i]; h[i] = cnt;
}
struct qus {
    int l, r, id;
}q[N];
bool cmp(qus A, qus B) {
    return A.r < B.r;
}
int main() {
    n = read(); m = read();
    for(int i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i) 
            if(pos[i] < pos[j]) add(pos[j], pos[i]);
            else add(pos[i], pos[j]);
    for(int i = 1; i <= m; i++) {
        q[i].l = read(); q[i].r = read(); q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp);
    for(int i = 1; i <= n; i++) {
        for(int k = h[i]; k; k = nxt[k]) add(num[k]), tot++;
        while(q[x].r == i) {
            ans[q[x].id] = tot;
            ans[q[x].id] -= sum(q[x].l - 1);
            x++;
        }
        if(x > m) break;
    }
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}