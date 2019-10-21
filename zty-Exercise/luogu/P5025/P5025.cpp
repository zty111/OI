#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt, l, mid
#define rson rt, mid + 1, r
const int N = 500010;
const int mod = 1e9 + 7;
int ll[N * 4], rr[N * 4], lef[N], rig[N], tor, tol, x[N], Rr[N], n, ans;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
void build(int o, int l, int r) {
	if(l == r) {
		ll[o] = lef[l];
		rr[o] = rig[r];
		return;
	}
	build(lson); build(rson);
	ll[o] = min(ll[lt], ll[rt]);
	rr[o] = max(rr[lt], rr[rt]);
}
void query(int o, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		tol = min(tol, ll[o]);
		tor = max(tor, rr[o]);
		return;
	}
	if(L <= mid) query(lson, L, R);
	if(R > mid) query(rson, L, R);
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) x[i] = read(), Rr[i] = read();
	for(int i = 1; i <= n; i++) {
		lef[i] = lower_bound(x+1, x+i, x[i] - Rr[i]) - x;
		rig[i] = upper_bound(x+1+i, x+n+1, x[i] + Rr[i]) - x - 1;
	}
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		int x = i, y = i;
		tol = i; tor = i;
		query(1, 1, n, x, y);
		while(tol != x || tor != y) {
			x = tol;
			y = tor;
			query(1, 1, n, x, y);
		}
		ans = (ans + i * (y - x + 1) % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}