#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 300010;
int n, a[N], c[N], m, s[N], ans[N], last[N];
map<int, int> pos;
struct qus{
    int l, r, id;
}q[N];
bool cmp(qus A, qus B) {
    if(A.r == B.r) return A.l < B.l;
    return A.r < B.r;
}
void add(int x, int d) {
    for(; x <= n; x += x & -x) c[x] ^= d;
}
int ask(int x) {
    int ret = 0;
    for(; x; x -= x & -x) ret ^= c[x];
    return ret;
}
int main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read(); s[i] = s[i-1] ^ a[i];
        if(!pos[a[i]]) pos[a[i]] = i;
    }
    m = read();
    for(int i = 1; i <= m; i++) {
        q[i].l = read(); q[i].r = read(); q[i].id = i;
    }
    sort(q+1, q+1+m, cmp);
    int p = 1;
    for(int i = 1; i <= m; i++) {
        while(p <= q[i].r) {
            if(last[pos[a[p]]]) add(last[pos[a[p]]], a[p]);
            add(p, a[p]);
            last[pos[a[p]]] = p;
            p++;
        }
        ans[q[i].id] = s[q[i].r] ^ s[q[i].l-1] ^ ask(q[i].r) ^ ask(q[i].l-1);
    }
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}