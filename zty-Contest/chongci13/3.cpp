#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
int n, m, k, u, v;
struct Mat{
    int m[101][101];
    void init() {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                m[i][j] = 0;
    }
};
Mat Mul(Mat A, Mat B) {
    Mat C; C.init();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                C.m[i][j] = (C.m[i][j] + (1ll * A.m[i][k] * B.m[k][j]) % mod) % mod;
    return C;
}
Mat qpow(Mat A, int b) {
    Mat R;
    for(int i = 1; i <= n; i++)
        R.m[i][i] = 1;
    while(b) {
        if(b & 1) R = Mul(R, A);
        A = Mul(A, A);
        b >>= 1;
    }
    return R;
}
int main() {
    n = read(); m = read(); k = read();
    Mat A; A.init();
    for(int i = 1; i <= m; i++) {
        u = read(); v = read();
        A.m[u][v] = 1;
    }
    A = qpow(A, k);
    Mat B; B.init();
    B.m[1][1] = 1;
    Mat C = Mul(B, A);
    for(int i = 1; i <= n; i++)
        printf("%d ", C.m[1][i]);
    printf("\n");
    return 0;
}