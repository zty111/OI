#include <bits/stdc++.h>
using namespace std;
const int u = 100010;
long long a[u][18][2], b[u][18][2], ansA, ansB, A, B;
int f[u][18][2], ans, n, m, t, i, h[u], g[u], go[u][2], l, k, j, x0, x, y;
struct rec{
    int x, y;
    bool operator < (rec b) const {
        return y < b.y;
    }
};
set<rec> s;
set<rec>::iterator it, lt, rt;
bool cmp(int a, int b) {
    if(abs(h[a] - h[i]) == abs(h[b] - h[i]))
        return h[a] < h[b];
    return abs(h[a] - h[i]) < abs(h[b] - h[i]);
}
void solve(int s, int x0, long long & A, long long & B){
    A = B = k = 0;
    for(int i = t; i >= 0; i--)
        if(f[s][i][k] && a[s][i][k] + b[s][i][k] <= x0){
            x0 -= a[s][i][k] + b[s][i][k];
            A += a[s][i][k]; B += b[s][i][k];
            if(i == 0) k ^= 1;
            s = f[s][i][k];
        }
}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >='0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
int main() {
    n = read();
    for(i = 1; i <= n; i++)
        h[i] = read();
    for(i = n; i; i--){
        rec now; now.x = i; now.y = h[i];
        s.insert(now);
        it = s.find(now);
        lt = it; rt = it; m = 0;
        if(lt != s.begin()) lt--, g[++m] = lt->x;
        if(lt != s.begin()) lt--, g[++m] = lt->x;
        if(rt++, rt != s.end()){
            g[++m] = rt->x;
            if(rt++, rt != s.end())g[++m] = rt->x;
        }
        sort(g + 1, g + m + 1, cmp);
        if(m) go[i][0] = g[1];
        if(m > 1) go[i][1] = g[2];
    }
    for(i = 1; i <= n; i++){
        if(go[i][1]) f[i][0][0] = go[i][1], a[i][0][0] = abs(h[go[i][1]] - h[i]), b[i][0][0] = 0;
        if(go[i][0]) f[i][0][1] = go[i][0], a[i][0][1] = 0, b[i][0][1]= abs(h[go[i][0]] - h[i]);
    }
    t = (int)(log(n * 1.0) / log(2.0) + 0.001);
    for(i = 1; i <= t; i++)
        for(j = 1; j <= n; j++)
            for(k = 0; k <= 1; k++){
                if(i == 1) l = k ^ 1;
                else l = k;
                if(f[j][i-1][k]) f[j][i][k] = f[f[j][i-1][k]][i-1][l];
                if(f[j][i][k]){
                    a[j][i][k] = a[j][i - 1][k] + a[f[j][i - 1][k]][i - 1][l];
                    b[j][i][k] = b[j][i - 1][k] + b[f[j][i - 1][k]][i - 1][l];
                }
            }
    x0 = read();
    ansA = 1; ansB = 0;
    for(i = 1; i <= n; i++){
        solve(i, x0, A, B);
        if(!B) A = 1;
        if(A * ansB < ansA * B || A * ansB == ansA * B && h[i] > h[ans]) ansA = A, ansB = B, ans = i;
    }
    printf("%d\n", ans);
    m = read();
    for(i = 1; i <= m; i++){
        x = read(); y = read();
        solve(x, y, A, B);
        printf("%lld %lld\n",A, B);
    }
    return 0;
}