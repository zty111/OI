#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 300010;
int n, a[N], is_it, b[N], m, l, r, c[N];
map<int, int> vis;
int main() {
    is_it = 1;
    n = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(a[i] != 0 && a[i] != 1) is_it = 0;
        c[i] = c[i-1] ^ a[i];
    }
    m = read();
    if(is_it) {
        for(int i = 1; i <= n; i++) {
            b[i] = b[i-1];
            if(a[i] == 1) b[i]++;
        }
        for(int i = 1; i <= m; i++) {
            l = read(); r = read();
            if((b[r] - b[l - 1]) % 2 != 0 || b[r] - b[l-1] == 0) printf("0\n");
            else printf("1\n");
        }
        return 0;   
    }
    for(int i = 1; i <= m; i++) {
        vis.clear();
        l = read(); r = read();
        int ans = c[r] ^ c[l-1];
        for(int i = l; i <= r; i++)
            if(vis[a[i]] == 0) vis[a[i]] = 1, ans ^= a[i];
        printf("%d\n", ans);
    }
    return 0;
}