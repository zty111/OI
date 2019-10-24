#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x * f;
}
const int N = 100010;
const int M = 200000;
int n, k, a[N], b[N], c[N], r[N], p[N], cnt, v[N], f[N], q[N], ans[N];
int bc[M + 10];
bool cmp(int x, int y) {
    if(a[x] != a[y]) return a[x] < a[y];
    if(b[x] != b[y]) return b[x] < b[y];
    return c[x] < c[y];
}
void add(int x, int v) {
    for(; x <= k; x += x & -x) bc[x] += v;
}
int ask(int x) {
    int ret = 0;
    for(; x; x -= x & -x) ret += bc[x];
    return ret;
}
void CDQ(int l, int r) {
    if(l == r) return;
    int mid = (l+r)>>1;
    CDQ(l, mid); CDQ(mid + 1, r);
    int p1 = l, p2 = mid + 1, p3 = l;
    while(p1 <= mid && p2 <= r) {
        if(b[p[p1]] <= b[p[p2]]) {
            add(c[p[p1]], v[p[p1]]);
            q[p3++] = p[p1++];
        } else {
            f[p[p2]] += ask(c[p[p2]]);
            q[p3++] = p[p2++];
        }
    }
    while(p1 <= mid) add(c[p[p1]], v[p[p1]]), q[p3++] = p[p1++];
    while(p2 <= r) f[p[p2]] += ask(c[p[p2]]), q[p3++] = p[p2++];
    for(int i = l; i <= mid; i++) add(c[p[i]], -v[p[i]]);
    for(int i = l; i <= r; i++) p[i] = q[i];
}
int main() {
    n = read(); k = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read(); b[i] = read(); c[i] = read();
        r[i] = i;
    }
    sort(r+1, r+1+n, cmp);
    p[++cnt] = r[1]; v[p[cnt]] = 1;
    for(int i = 2; i <= n; i++)
        if(a[r[i]] == a[r[i-1]] && b[r[i]] == b[r[i-1]] && c[r[i]] == c[r[i-1]]) v[p[cnt]]++;
        else p[++cnt] = r[i], v[p[cnt]] = 1;
    CDQ(1, cnt);
    for(int i = 1; i <= cnt; i++)
        ans[f[p[i]] + v[p[i]] - 1] += v[p[i]];
    for(int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}