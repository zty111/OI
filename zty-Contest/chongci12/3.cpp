#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, x[N], ans[N], now, L, R, c[N], pla[N];
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
struct qus {
    int l, r, id, pos;
}q[N];
bool cmp(qus A, qus B) {
    if(A.pos == B.pos) {
        if(A.pos % 2 == 1)
            return A.r < B.r;
        else return A.r > B.r;
    }
    return A.pos < B.pos;
}
inline void del(int p) {
    int use = x[p];
    for(int i = use; i <= n; i += use)
        if(pla[i] <= R && pla[i] >= L) now--;
    int sq_use = sqrt(use);
    for(int i = 2; i <= sq_use; i++)
        if(use % i == 0) {
            if(pla[i] <= R && pla[i] >= L) now--;
            int v1 = use / i;
            if(v1 == i) continue;
            if(pla[i] <= R && pla[i] >= L) now--;
        }
}
inline void add(int p) {
    int use = x[p];
    for(int i = use; i <= n; i += use)
        if(pla[i] <= R && pla[i] >= L) now++;
    int sq_use = sqrt(use);
    for(int i = 2; i <= sq_use; i++)
        if(use % i == 0) {
            if(pla[i] <= R && pla[i] >= L) now++;
            int v1 = use / i;
            if(v1 == i) continue;
            if(pla[i] <= R && pla[i] >= L) now++;
        }
}
int main() {
    n = read(); m = read();
    int lpos = sqrt(n);
    for(int i = 1; i <= n; i++) x[i] = read(), pla[x[i]] = i;
    for(int i = 1; i <= m; i++) {
        q[i].l = read(); q[i].r = read(); q[i].id = i; q[i].pos = q[i].l / lpos;
    }
    sort(q+1, q+1+m, cmp);
    for(int i = 1; i <= m; i++) {
        while(L < q[i].l) ++L, del(L - 1);
        while(L > q[i].l) add(L - 1), --L;
        while(R > q[i].r) --R, del(R + 1);
        while(R < q[i].r) add(R + 1), ++R;
        ans[q[i].id] = now + R - L + 1;
    }
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}