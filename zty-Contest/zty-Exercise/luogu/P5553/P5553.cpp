#include <cstdio>
using namespace std;
const int mod = 998244353;
int T;
long long n;
int qpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    } return ret;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n >= mod) printf("-1\n");
        else if(n & 1) printf("%lld\n", 2ll * qpow(n+1, mod-2) % mod);
        else printf("0\n");
    }
    return 0;
}