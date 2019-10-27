#include <cstdio>
#include <iostream>
using namespace std;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
const int N = 1e6 + 5;
int v[N], a[N], ans, Ans;
inline void add(int x) {
    if(!v[a[x]]) ans++;
    v[a[x]]++;
}
inline void del(int x) {
    v[a[x]]--;
    if(!v[a[x]]) ans--;
}
int main() {
    int T = read();
    while(T--) {
        int n = read(), k = read(), d = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        int l = 1, r = 0;
        while(r - l + 1 < d) add(++r);
        Ans = ans;
        while(r < n) {
            del(l++); add(++r);
            Ans = min(Ans, ans);
        }
        while(l <= r) del(l++);
        printf("%d\n", Ans);
    }
    return 0;
}