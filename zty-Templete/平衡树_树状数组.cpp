#include <bits/stdc++.h>
using namespace std;
// 快读
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
// 平衡树_树状数组
const int N = 1 << 25;
const int p = 1e7;
int a[N + 10], n, opt, x;
void add(int x, int k) {
    while(x <= N) {
        a[x] += k;
        x += x & -x;
    }
}
int query(int x) {
    int ans = 0;
    while(x) {
        ans += a[x];
        x -= x & -x;
    } return ans;
}
int kth(int x) {
    int rt = N;
    for(int i = N; i; i >>= 1) {
        if(a[rt - i] >= x) rt -=i;
        else x -= a[rt - i];
    } return rt - p;
}
// insert : add(x, 1)
// remove : add(x, -1)
// query : query(x)
// kth : kth(x)
// pre : kth(query(x - 1)) // 不查询 x 后 -1 是因为 x 可能有多个
// suf : kth(query(x) + 1) // 不查询 x + 1 因为 x + 1 没有数的话与 x 同
int main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        opt = read(); x = read();
        switch(opt) {
            case 1: add(x + p, 1); break;
            case 2: add(x + p, -1); break;
            case 3: printf("%d\n", query(x + p - 1) + 1); break;
            case 4: printf("%d\n", kth(x)); break;
            case 5: printf("%d\n", kth(query(x + p - 1))); break;
            case 6: printf("%d\n", kth(query(x + p) + 1)); break;
        }
    }
    return 0;
}