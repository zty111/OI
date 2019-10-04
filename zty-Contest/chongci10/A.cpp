#include <bits/stdc++.h>
using namespace std;
struct bat {
    long long m[11][11];
    void init() {
        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 11; j++)
                m[i][j] = 0;
    }
}E;
const long long mod = 1000000007;
bat Mul(bat A, bat B) {
    bat C; C.init();
    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 11; j++)
            for(int k = 0; k < 11; k++)
                C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j] % mod + mod) % mod;
    return C;
}
bat qpow(bat A, long long b) {
    bat C; C = E;
    while(b) {
        if(b & 1) C = Mul(C, A);
        A = Mul(A, A);
        b >>= 1;
    } return C;
}
const int ans[10] = {1,1,2,3,5,8,13,21,34,55};
int main() {
    for(int i = 0; i < 11; i++)
        E.m[i][i] = 1;
    int T;
    long long n;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n <= 9) printf("%d\n", ans[n]);
        else {
            bat A; A.init();
            A.m[0][0] = A.m[0][1] = 1; A.m[0][10] = -1;
            for(int i = 1; i <= 10; i++) A.m[i][i - 1] = 1;
            A = qpow(A, n - 10);
            bat B; B.init();
            B.m[0][0] = 88;
            for(int i = 1; i <= 10; i++) B.m[i][0] = ans[10 - i];
            B = Mul(A, B);
            printf("%lld\n", B.m[0][0]);
        }
    }
    return 0;
}