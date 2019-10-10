#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
int n, c[N], L, q[N];
typedef long long ll;
double sum[N], dp[N];
inline double a(int i) {return sum[i] + i;}
inline double b(int i) {return sum[i] + i - 1 - L;}
inline double x(int i) {return a(i);}
inline double y(int i) {return dp[i] + a(i) * a(i);}
inline double k(int i, int j) {return (y(j) - y(i)) / (x(j) - x(i));}
int main() {
    scanf("%d %d", &n, &L);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]), sum[i] = sum[i - 1] + c[i];
    int tail = 1, head = 1;
    for(int i = 1; i <= n; i++) {
        while(head < tail && k(q[head], q[head + 1]) < 2 * b(i)) head++;
        dp[i] = dp[q[head]] + (b(i) - a(q[head])) * (b(i) - a(q[head]));
        while(head < tail && k(q[tail - 1], q[tail]) > k(q[tail - 1], i)) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", (ll)dp[n]);
    return 0;
}