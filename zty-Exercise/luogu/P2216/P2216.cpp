#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1010;
int a, b, n, x[N][N], y[N][N], X[N][N], Y[N][N], w[N][N], h1, h2, t1, t2, q[N], Q[N];
int main() {
    scanf("%d %d %d", &a, &b, &n);
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            scanf("%d", &w[i][j]);
    for(int i = 1; i <= a; i++) {
        h1 = t1 = h2 = t2 = q[1] = Q[1] = 1;
        for(int j = 2; j <= b; j++) {
            while(h1 <= t1 && w[i][j] >= w[i][q[t1]]) t1--;
            while(h2 <= t2 && w[i][j] <= w[i][Q[t2]]) t2--;
            q[++t1] = Q[++t2] = j;
            while(j - q[h1] >= n) h1++;
            while(j - Q[h2] >= n) h2++;
            if(j >= n) X[i][j-n+1] = w[i][q[h1]], x[i][j-n+1] = w[i][Q[h2]];
        }
    }
    for(int i = 1; i <= b - n + 1; i++) {
        h1 = t1 = h2 = t2 = q[1] = Q[1] = 1;
        for(int j = 2; j <= a; j++) {
            while(h1 <= t1 && X[j][i] >= X[q[t1]][i]) t1--;
            while(h2 <= t2 && x[j][i] <= x[Q[t2]][i]) t2--;
            q[++t1] = Q[++t2] = j;
            while(j - q[h1] >= n) h1++;
            while(j - Q[h2] >= n) h2++;
            if(j >= n) Y[j-n+1][i] = X[q[h1]][i], y[j-n+1][i] = x[Q[h2]][i];
        }
    }
    int ans = 1e9 + 10;
    for(int i = 1; i <= a - n + 1; i++)
        for(int j = 1; j <= b - n + 1; j++)
            ans = min(ans, Y[i][j] - y[i][j]);
    printf("%d\n", ans);
    return 0;
}