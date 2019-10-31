#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void read(int&x){
    char ch=getchar();x=0;while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}

const int p = 998244353;
inline int qm(const int x) {return x < p ? x : x - p;}
inline void pls(int&x, const int&y) {x = x+y < p ? x+y : x+y-p;}

const int N = 1010, M = 2503;
bool city_hate[N];
int city_sum[N], hate[N], b[N], s[N];
int f[M], pre_f[M], F[M][M];
int g[M], pre_g[M], G[M][M];
int n, c;

void work() {
    read(n), read(c);
    int C0, C1, D0, D1, ALL = 0;
    for(int i=1;i<=c;++i) city_hate[i] = false, city_sum[i] = 0;
    read(C0), read(C1), read(D0), read(D1);
    for(int i=1;i<=n;++i) read(b[i]), read(s[i]), city_sum[b[i]] += s[i], hate[i] = -1, ALL += s[i];
    int K, x; read(K);
    while(K--) read(x), read(hate[x]), city_hate[b[x]] = true;

    memset(f, 0, sizeof f), pre_f[0] = f[0] = 1;
    for(int i=1;i<=c;++i)
        if(!city_hate[i] and city_sum[i])
            for(int j = C0, ts = city_sum[i]; j >= ts; -- j)
                pls(f[j], f[j-ts]);
    for(int i=1;i<=C0;++i) pre_f[i] = qm(pre_f[i-1] + f[i]);

    memset(g, 0, sizeof g), pre_g[0] = g[0] = 1;
    for(int i=1;i<=n;++i)
        if(-1 == hate[i])
            for(int j = D0, ts = s[i]; j >= ts; -- j)
                pls(g[j], g[j-ts]);
    for(int i=1;i<=D0;++i) pre_g[i] = qm(pre_g[i-1] + g[i]);

    int Cs = 0, Ss = 0;
    memset(F, 0, sizeof F), F[0][0] = 1;
    memset(G, 0, sizeof G);
    for(int ct = 1; ct <= c; ++ ct)
        if(city_hate[ct]) {
            Cs += city_sum[ct], Cs = min(Cs, C0);
            for(int i=0;i<=Cs;++i)
            for(int j=0;j<=Ss;++j) G[i][j] = F[i][j];

            for(int a=1;a<=n;++a)
                if(b[a] == ct and ~hate[a]) {
                    const int t = s[a];
                    Ss += t, Ss = min(Ss, D0);
                    if(hate[a] == 1)
                        for(int i=0;i<=Cs;++i) {
                            for(int j=Ss;j>=t;--j) F[i][j] = F[i][j-t];
                            for(int j=t-1;~j;--j) F[i][j] = 0;
                        }
                    if(hate[a] >= 2)
                        for(int i=0;i<=Cs;++i)
                        for(int j=Ss;j>=t;--j) pls(F[i][j], F[i][j-t]);
                    if(hate[a] == 3)
                        for(int i=0;i<=Cs;++i) {
                            for(int j=Ss;j>=t;--j) G[i][j] = G[i][j-t];
                            for(int j=t-1;~j;--j) G[i][j] = 0;
                        }
                    if(hate[a] <= 1)
                        for(int i=0;i<=Cs;++i)
                        for(int j=Ss;j>=t;--j) pls(G[i][j], G[i][j-t]);
                }
            for(int j=0,t=city_sum[ct];j<=Ss;++j) {
                for(int i=Cs;i>=t;--i) F[i][j] = F[i-t][j];
                for(int i=t-1;~i;--i) F[i][j] = 0;
            }
            for(int i=0;i<=Cs;++i)
            for(int j=0;j<=Ss;++j)
                pls(F[i][j], G[i][j]);
        }

    int res = 0;
    for(int i=0;i<=Cs;++i)
    for(int j=0;j<=Ss;++j) {
        int l1 = max(0, ALL - C1 - i), r1 = C0 - i; if(l1 > r1) continue;
        int l2 = max(0, ALL - D1 - j), r2 = D0 - j; if(l2 > r2) continue;
        int vf = pre_f[r1]; if(l1) vf += p - pre_f[l1-1];
        int vg = pre_g[r2]; if(l2) vg += p - pre_g[l2-1];
        pls(res, (ll)vf * vg%p * F[i][j]%p);
    }
    printf("%d\n", res);
}

int main() {
    int T; read(T);
    while(T--) work();
    return 0;
}