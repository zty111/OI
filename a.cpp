#include <cstdio>
#include <iostream>
using namespace std;
int T;
int main() {
    scanf("%d\n", &T);
    while(T--) {
        int a, b, c, d, k, e = 0, f = 0;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        while(a > 0) a -= c, e++;
        while(b > 0) b -= d, f++;
        if(e + f > k) printf("-1\n");
        else printf("%d %d\n", e, f);
    }
    return 0;
}