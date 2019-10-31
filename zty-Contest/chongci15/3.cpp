#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
struct qus {
    ll a, b, c, d, l;
}q[100];
ll T[100], num[100];
const ll mod = 1e9 + 7;
map<pair<ll, ll>, ll> m1;
map<pair<ll,pair<ll, ll> >, ll>m2;
ll dist(ll o, ll u, ll v) {
    if(o == 0 || u == v) return 0;
    pair<ll, pair<ll, ll> > p = make_pair(o, make_pair(u, v));
    if(m2.count(p)) return m2[p];
    if(u < num[q[o].a]) {
        if(v < num[q[o].a]) return m2[p] = dist(q[o].a, u, v);
        else return m2[p] = (dist(q[o].a, u, q[o].c) + dist(q[o].b, v - num[q[o].a], q[o].d) + q[o].l) % mod;
    } else {
        if(v >= num[q[o].a]) return m2[p] = dist(q[o].b, u - num[q[o].a], v - num[q[o].a]);
        else return m2[p] = (dist(q[o].a, v, q[o].c) + dist(q[o].b, u - num[q[o].a], q[o].d) + q[o].l) % mod;
    }
}
ll dfs(ll o, ll u) {
    if(o == 0) return 0;
    pair<ll, ll> p = pair<ll, ll>(o, u);
    if(m1.count(p)) return m1[p];
    if(u < num[q[o].a])
        return m1[p] = ((dfs(q[o].a, u) + dfs(q[o].b, q[o].d)) % mod + (dist(q[o].a, q[o].c, u) + q[o].l) * num[q[o].b] % mod) % mod;
    else 
        return m1[p] = ((dfs(q[o].a, q[o].c) + dfs(q[o].b, u - num[q[o].a])) % mod + (dist(q[o].b, q[o].d, u - num[q[o].a]) + q[o].l) * num[q[o].a] % mod) % mod;
}
signed main() {
    ll m = read();
    num[0] = 1;
    for(ll i = 1; i <= m; i++) {
        q[i].a = read(); q[i].b = read(); q[i].c = read(); q[i].d = read(); q[i].l = read();
        num[i] = num[q[i].a] + num[q[i].b];
        T[i] = (num[q[i].a] * dfs(q[i].b, q[i].d) % mod + num[q[i].b] * dfs(q[i].a, q[i].c) % mod + num[q[i].a] * num[q[i].b] % mod * q[i].l % mod + T[q[i].a] + T[q[i].b]) % mod;
        printf("%lld\n", T[i]);
    }
    return 0;
}