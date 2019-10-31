#include <cstdio>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x * f;
}
const int N = 1000010;
int n, a, b, c, q[N], tail, head;
long long x[N], f[N];
inline double k (int i, int j) {
    double kk = (double)(((f[i] + a * x[i] * x[i] - b * x[i]) - (f[j] + a * x[j] * x[j] - b * x[j])) / (double)(x[i] - x[j]));
    return kk;
}
int main() {
    n = read(); a = read(); b = read(); c = read();
    for(int i = 1; i <= n; i++) x[i] = read(), x[i] += x[i - 1];
    for(int i = 1; i <= n; i++) {
        while(head < tail && k(q[head], q[head + 1]) >= 2.0 * a * x[i]) head++;
        int j = q[head];
        f[i] = f[j] + (x[i] - x[j]) * (x[i] - x[j]) * a + (x[i] - x[j]) * b + c;
        while(head < tail && k(q[tail - 1], i) >= k(q[tail - 1], q[tail])) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", f[n]);
    return 0;
}