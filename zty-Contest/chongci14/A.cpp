#include <cstdio>
#include <cstring>
using namespace std;
int gcd(int a, int b) {
    if(!b) return a;
    else return gcd(b, a % b);
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 300010;
int T, n, m, k, num, vis[N], x;
int main() {
    T = read();
    while(T--) {
        memset(vis, 0, sizeof(vis));
        int flag = 0;
        n = read(); m = read(); k = read();
        int GCD = gcd(n, m); GCD = gcd(GCD, k);
        if(GCD > 300000) flag = 1;
        for(int i = 1; i <= 3; i++) {
            num = read();
            for(int j = 1; j <= num; j++) {
                x = read() % GCD;
                if(!flag) vis[x] = 1;
            }
        }
        if(!flag) for(int i = 0; i < GCD; i++) if(!vis[i]) flag = 1;
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}