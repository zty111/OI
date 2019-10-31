#include <cstdio>
using namespace std;
int T, n, ans, a[1010];
int main() {
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int now = 0;
        for(int i = 2; i <= n; i++) {
            now ^= 1;
            int x = a[i] - a[i-1];
            ans ^= x;
        }
        if(ans) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}