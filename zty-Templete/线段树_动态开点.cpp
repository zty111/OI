#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
// 线段树，维护区间最大值
struct segmentTree {
    int lc, rc;
    int dat;
} tr[N * 2];
int root,tot;
//动态开点 空间 mlogn
int build() {
    tot++;
    tr[tot].lc = tr[tot].rc = tr[tot].dat = 0;
    return tot;
}
// 在p处插入单点k
void insert(int o, int l, int r, int p, int k) {
    if(l == r) {
        tr[o].dat += k;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) {
        if(!tr[o].lc) tr[o].lc = build();
        insert(tr[o].lc, l, mid, p, k);
    } else {
        if(!tr[o].rc) tr[o].rc = build();
        insert(tr[o].rc, mid + 1, r, p, k);
    }
    tr[o].dat = max(tr[tr[o].lc].dat, tr[tr[o].rc].dat);
}
// 合并p, q两个线段树
int merge(int p, int q, int l, int r) {
    if(!p) return q;
    if(!q) return p;
    if(l == r) {
        tr[p].dat += tr[q].dat;
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].lc = merge(tr[p].lc, tr[q].lc, l, mid);
    tr[p].rc = merge(tr[p].rc, tr[q].rc, mid + 1, r);
    tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat);
    return p;
}
int main() {
    tot = 0;
    root = build();
    // insert(root, 1, n, val, delta);
    // merge(p, q, 1, n);
}