#include<bits/stdc++.h>
using namespace std;
int n, q, m, p, b;
inline char nc(){
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1==p2 && (p2= (p1=buf) + fread(buf,1,100000,stdin), p1==p2)? EOF : *p1++;
}
inline int read(){
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = (x<<3) + (x<<1) + ch - 48, ch = nc();
    return x * f;
}
int qpow(int a, long long b, int m){
    int r = 1; a %= m;
    while(b) {
        if(b&1) r = 1ll * r * a % m;
        a = 1ll * a * a % m;
        b = b >> 1;
    } return r;
}
int pll(int a){
    int cnt = a;
    for(int i = 2; i <= sqrt(a+0.5); i++) {
        if(a % i == 0) {
            cnt = cnt / i * (i-1);
            while(a % i == 0) a /= i;
        }
    }
    if(a > 1)cnt = cnt / a * (a-1);
    return cnt;
}
int mod;
struct Matrix {
    int a[3][3];
    Matrix() { memset(a, 0, sizeof a); } // 构造函数，矩阵初始化全零
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 2; ++j)
                for (int k = 1; k <= 2; ++k)
                    res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} ans, base;
void init() { // 初始化 ans、base 矩阵
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ans.a[1][1] = ans.a[1][2] = 1;
}
void qpow2(int b) { // 求
    while (b) {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}
int F(int n) {
    if (n <= 2) return 1;
    init();
    qpow2(n - 2);
    return ans.a[1][1] % mod;
}
int main() {
    m = read(); p = read();
    for(int i = 1; i <= m; i++) {
        n = read(); q = read();
        if(q == 1) {
            printf("0\n");
            continue;
        }
        int pi = pll(q);
        mod = pi;
        int fn = F(n);
        b = fn + pi;
        printf("%d\n", qpow(p, b, q));
    }
    return 0;
}