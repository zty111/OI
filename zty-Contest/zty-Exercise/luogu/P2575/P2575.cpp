#include <cstdio>
#include <cstring>
using namespace std;
int T, n, m, p[25], ans;
int main() {
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &m); memset(p, 0, sizeof(p));
            for(int j = 1, x; j <= m; j++)
                scanf("%d", &x), p[x] = 1;
            int cnt = 0, tot = 0;
            for(int j = 20; j; j--) {
                if(!p[j]) {
                    ans ^= tot;
                    tot = 0;
                    cnt ^= 1;
                } else if(cnt) ++tot;
            }
            ans ^= tot;
        }
        if(!ans) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}