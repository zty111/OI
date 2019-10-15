#include <iostream>
#include <cstdio>
using namespace std;
#define int unsigned long long
int T, n, a, b, m, f[1010000], l;
int qpow(int a, int b) {
    a %= l;
    int ret = 1;
    while(b) {
        if(b&1ull) ret = ret * a % l;
        a = a * a % l;
        b >>= 1;
    } return ret;
}
signed main() {
    scanf("%llu", &T);
    while(T--) {
        scanf("%llu %llu %llu", &a, &b, &n);
        if(n == 1llu) {printf("0\n"); continue;}
        f[0] = 0; f[1] = 1;
        for(int i = 2;; i++) {
            f[i] = (f[i-1] + f[i-2]) % n;
            if(f[i] == 1 && f[i-1] == 0) {
                l = i - 1; break;            
            }
        }
        m = qpow(a, b);
        printf("%llu\n", f[m]);
    }
    return 0;
}