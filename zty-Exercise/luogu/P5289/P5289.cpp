#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int mod = 998244353;
const int N = 5000;
inline void pls(int & a, int b) {a = a + b < mod ? a + b : a + b - mod;}
inline int qm(int a) {return a = a >= mod ? a - mod : a;}
int b[N], s[N], city_sum[N], hate[N];
bool city_hate[N];
int f[N], pre_f[N], F[N][N];
int g[N], pre_g[N], G[N][N];
void solve() {
    int n = read(), c = read();
    int c0 = read(), c1 = read(), d0 = read(), d1 = read(), Sum = 0;
    for(int i = 1; i <= c; i++) city_hate[i] = false, city_sum[i] = 0;
    for(int i = 1; i <= n; i++) {
        b[i] = read(); s[i] = read();
        city_sum[b[i]] += s[i];
        Sum += s[i];
        hate[i] = -1;
    }
    int k = read();
    while(k--) {
        int x = read(); hate[x] = read();
        city_hate[b[x]] = true;
    }

    memset(f, 0 ,sizeof(f)); pre_f[0] = f[0] = 1;
    for(int i = 1; i <= c; i++) {
        if(!city_hate[i] && city_sum[i])
            for(int j = c0, ts = city_sum[i]; j >= ts; j--)
                pls(f[j], f[j - ts]);
    }
    for(int i = 1; i <= c0; i++) pre_f[i] = qm(pre_f[i - 1] + f[i]);

    memset(g, 0 ,sizeof(g)); pre_g[0] = g[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(hate[i] == -1)
            for(int j = d0, ts = s[i]; j >= ts; j--)
                pls(g[j], g[j - ts]);
    }
    for(int i = 1; i <= d0; i++) pre_g[i] = qm(pre_g[i - 1] + g[i]);
    int cs = 0, ss = 0;
    memset(F, 0, sizeof(F)); F[0][0] = 1;
    memset(G, 0, sizeof(G));
    for(int ct = 1; ct <= c; ct++)
        if(city_hate[ct]){
            cs += city_sum[ct]; cs = min(cs, c0);
            for(int i = 0; i <= cs; i++)
                for(int j = 0; j <= ss; j++)
                    G[i][j] = F[i][j];
            
            for(int i = 1; i <= n; i++)
                if(b[i] == ct && ~hate[i]) {
                    int t = s[i];
                    ss += t; ss = min(ss, d0);
                    if(hate[i] == 1)
                        for(int j = 0; j <= cs; j++) {
                            for(int z = ss; z >= t; z--) F[j][z] = F[j][z - t];
                            for(int z = t - 1; ~z; z--) F[j][z] = 0;
                        }
                    if(hate[i] == 2 || hate[i] == 3)
                        for(int j = 0; j <= cs; j++)
                            for(int z = ss; z >= t; z--) pls(F[j][z], F[j][z - t]);
                    if(hate[i] == 3)
                        for(int j = 0; j <= cs; j++) {
                            for(int z = ss; z >= t; z--) G[j][z] = G[j][z - t];
                            for(int z = t - 1; ~z; z--) G[j][z] = 0;
                        }
                    if(hate[i] == 1 || hate[i] == 0) 
                        for(int j = 0 ; j <= cs; j++)
                            for(int z = ss; z >= t; z--) pls(G[j][z], G[j][z - t]);
                }
            for(int j = 0, t = city_sum[ct]; j <= ss; j++) {
                for(int i = cs; i >= t; i--) F[i][j] = F[i - t][j];
                for(int i = t - 1; ~i; i--) F[i][j] = 0;
            }
            for(int i = 0; i <= cs; i++)
                for(int j = 0; j <= ss; j++)
                    pls(F[i][j], G[i][j]);
        }
    int ans = 0;
    for(int i = 0; i <= cs; i++)
        for(int j = 0; j <= ss; j++) {
            int l1 = max(0, Sum - c1 - i), r1 = c0 - i; if(l1 > r1) continue;
            int l2 = max(0, Sum - d1 - j), r2 = d0 - j; if(l2 > r2) continue;
            int vf = pre_f[r1]; if(l1) vf += mod - pre_f[l1 - 1];
            int vg = pre_g[r2]; if(l2) vg += mod - pre_g[l2 - 1];
            pls(ans, (long long)vf * vg % mod * F[i][j] % mod);
        }
    printf("%d\n", ans);
}
int main() {
    int T = read();
    while(T--) solve();
    return 0;
}