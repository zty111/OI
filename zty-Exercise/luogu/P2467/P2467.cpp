#include <bits/stdc++.h>
using namespace std;
const int N = 4201;
int n, p, f[N][N];
int main() {
    scanf("%d %d", &n, &p);
    f[2][2] = 1;
    for(int i = 3; i <= n; i++)
        for(int j = 2; j <= i; j++)
            f[i][j] = (f[i][j-1] + f[i-1][i-j+1]) % p;
    int ans = 0;
    for(int i = 2; i <= n; i++)
        ans = (ans + f[n][i]) % p;
    printf("%d\n", (ans<<1) % p);
    return 0;
}