#include <bits/stdc++.h>
using namespace std;
int sg(int x, int y) {
    int tmp = (x-1) | (y-1) , res = 0;
    while(tmp & 1) {
        res++;
        tmp >>= 1;
    }
    return res;
}
int main() {
    int T, n, SG;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); n /= 2;
        SG = 0;
        for(int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            SG ^= sg(x, y);
        }
        if(SG) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}