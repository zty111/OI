#include <bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
#define lson tr[o].lc, l, mid
#define rson tr[o].rc, mid + 1, r
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 3e6 + 5;
struct tree {
    int lc, rc;
    int siz;
    long long val;
}tr[N * 12];
int n, m, q, x, y, root[N], tot, M, rt, d[N];
int build() {
    tot++;
    tr[tot].lc = tr[tot].rc = 0;
    tr[tot].val = 0;
    tr[tot].siz = -1;
    return tot;
}
int tim;
long long query(int o, int l, int r, int wh, int opt) {
  //if(tim==91)cout<<"query "<<o<<' '<<l<<' '<<r<<' '<<wh<<' '<<opt<<endl;
    if(tr[o].siz == -1) tr[o].siz = r - l + 1;
    --tr[o].siz;
    //if(tim==91)cout<<o<<' '<<l<<' '<<r<<' '<<tr[o].siz<<endl;
    if(l == r) {
        if(opt) {
            if(l < m) return 1ll * (x - 1) * m + l;
            else return tr[o].val;
        } else {
            if(l <= n) return 1ll * l * m;
            else return tr[o].val;
        }      
    }
    if(!tr[o].lc) { 
        tr[o].lc = build();
        tr[tr[o].lc].siz = mid - l + 1;
    }
    if(wh <= tr[tr[o].lc].siz) { 
        if(!tr[o].lc) tr[o].lc = build();
        return query(lson, wh, opt);
    } else {
        if(!tr[o].rc) tr[o].rc = build();
        return query(rson, wh - tr[tr[o].lc].siz, opt);
    }
}
void insert(int o, int l, int r, int wh, long long v) {
//   cout<<"insert "<<o<<' '<<l<<' '<<r<<' '<<wh<<' '<<v<<endl;
    if(tr[o].siz == -1) tr[o].siz = r - l + 1;
    if(l == r) {
        tr[o].val = v;
        return;
    }
    if(wh <= mid) {
        if(!tr[o].lc) tr[o].lc = build();
        insert(lson, wh, v);
    } else {
        if(!tr[o].rc) tr[o].rc = build();
        insert(rson, wh, v);
    }
}
int main() {
    n = read(); m = read(); q = read();
    M = m + q; rt = build();
    for(int i = 1; i <= q; i++) {
        x = read(); y = read();
        if(y < m) {
            if(!root[x]) root[x] = build();
            long long ans = query(root[x], 1, M, y, 1);
            printf("%lld\n", ans);
            long long val = query(rt, 1, n + q, x, 0);
            d[x]++; d[0]++;
            insert(root[x], 1, M, m - 1 + d[x], val);
            insert(rt, 1, n + q, n + d[0], ans);
        } else {
            long long ans = query(rt, 1, n + q, x, 0);
            printf("%lld\n", ans);
            d[0]++;
            insert(rt, 1, n + q, n + d[0], ans);
        }
    }
    return 0;
}