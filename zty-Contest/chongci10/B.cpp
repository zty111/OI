#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x * f;
}
int n, m, l, r, ans, opt;
const int N = 200010 << 2;
int a[N], ma[N], mi[N], sum[N], flag[N];
#define mid ((l + r) >> 1)
#define lt (o << 1)
#define rt (o << 1 | 1)
#define lson lt, l, mid
#define rson rt, mid + 1, r
inline void pushup(int o) {
    sum[o] = sum[lt] + sum[rt];
    ma[o] = max(ma[lt], ma[rt]);
    mi[o] = min(mi[lt], mi[rt]);
}
void build(int o, int l, int r) {
    if(l == r) {
        sum[o] = ma[o] = mi[o] = a[l];
        flag[o] = 0;
        return;
    }
    build(lson); build(rson);
    pushup(o);
}
inline void change(int o) {
    int mx = -mi[o];
    mi[o] = -ma[o];
    ma[o] = mx;
    sum[o] = -sum[o];
}
inline void pushdown(int o) {
    flag[o] = 0;
    flag[lt] ^= 1; flag[rt] ^= 1;
    change(lt); change(rt);
}
void update(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        if(opt == 1) {
            sum[o] = ma[o] = mi[o] = v;
            return;
        } else if(opt == 2) {
            sum[o] += v;
            ma[o] = mi[o] = sum[o];
            return;
        } else {
            change(o);
            flag[o] ^= 1;
            return;
        }
    }
    if(flag[o]) pushdown(o);
    if(L <= mid) update(lson, L, R, v);
    if(R > mid) update(rson, L, R, v);
    pushup(o);
}
int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        if(opt == 4) {
            return ma[o];
        } else if(opt == 5) {
            return mi[o];
        } else {
            return sum[o];
        }
    }
    int Ans;
    if(opt == 4) Ans = -0x3f3f3f3f;
    else if(opt == 5) Ans = 0x3f3f3f3f;
    else Ans = 0;
    if(flag[o]) pushdown(o);
    if(L <= mid) {
        if(opt == 4)
            Ans = max(Ans, query(lson, L, R));
        else if(opt == 5)
            Ans = min(Ans, query(lson, L, R));
        else Ans += query(lson, L, R);
    }
    if(R > mid) {
        if(opt == 4)
            Ans = max(Ans, query(rson, L, R));
        else if(opt == 5)
            Ans = min(Ans, query(rson, L, R));
        else Ans += query(rson, L, R);
    }
    return Ans;
}
int main() {
    memset(mi, 0x3f, sizeof(mi));
    memset(ma, -0x3f, sizeof(ma));
    n = read(); m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        opt = read(); l = read(); r = read();
        l = (l ^ ans) % n + 1;
        if(opt >= 3) {
            r = (r ^ ans) % n + 1;
            if(l > r) swap(l, r);
        }
        switch(opt) {
            case 1: update(1, 1, n, l, l, r); break;
            case 2: update(1, 1, n, l, l, r); break;
            case 3: update(1, 1, n, l, r, 0); break;
            case 4: ans = query(1, 1, n, l, r); break;
            case 5: ans = query(1, 1, n, l, r); break;
            case 6: ans = query(1, 1, n, l, r); break;
        }
        if(opt >= 4) printf("%d\n", ans), ans = abs(ans);
    }
    return 0;
}