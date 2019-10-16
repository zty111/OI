#include <iostream>
#include <cstdio>
using namespace std;
int T, n, x, ans, f, h;
inline int getk() {
    char ch = getchar();
    while(ch != '0' && ch != '1') ch = getchar();
    return ch - 48;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        x = 0; ans = 0; f = 0; h = 0;
        for(int i = 1; i <= n; i++) {
            x = getk();
            if(x) {
                if(!f) f = i;
                h = i;
            }
        }
        if(h == 0) ans = n;
        else ans = max(2 * (n - f + 1), 2 * h);
        printf("%d\n", ans);
    }
    return 0;
}