#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;
const int m = 1 << 8;
const int inf = 0x3f3f3f3f;
int c, n, t[N], b[N], f[N][m][20];
int main() {
    scanf("%d", &c);
    while(c--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &t[i], &b[i]);
        memset(f, 0x3f, sizeof(f));
        f[1][0][7] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < m; j++)
                for(int k = -8; k <= 7; k++)
                    if(f[i][j][k+8] != inf) {
                        if(j & 1) f[i+1][j>>1][k+7] = min(f[i+1][j>>1][k+7], f[i][j][k+8]);
                        else {
                            int r = inf;
                            for(int h = 0; h <= 7; h++)
                                if(!((j>>h) & 1)) {
                                    if(i + h > r) break;
                                    r = min(r, i + h + b[i+h]);
                                    f[i][j|(1<<h)][h+8] = min(f[i][j|(1<<h)][h+8], f[i][j][k+8] + (i + k ? (t[i+k] ^ t[i+h]) : 0));
                                }
                        }
                    }
        int res = inf;
        for(int k = 0; k <= 8; k++)
            res = min(res, f[n+1][0][k]);
        printf("%d\n", res);
    }
    return 0;
}