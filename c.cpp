#include <iostream>
#include <cstdio>
using namespace std;
long long n, p, d, w, l, r, x, y, z;
bool ok;
bool check(int q) {
    int now = p - d * q;
    if(now % (w - d) == 0) {
        x = now / (w - d);
        y = q - x;
        ok = 1;
    }
    return now * w > p;
}
int main() {
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    l = 0; r = n;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
        if(ok) break;
    }
    printf("%lld %lld %lld\n", x, y, z);
    return 0;
}