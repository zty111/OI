#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m, a[N][N], l[N][N], r[N][N], up[N][N], ans1, ans2;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), l[i][j] = j, r[i][j] = j;
    for(int i = 1; i <= n; i++)
        for(int j = 2; j <= m; j++)
            if(a[i][j] != a[i][j-1])
                l[i][j] = l[i][j-1];
    for(int i = 1; i <= n; i++)
        for(int j = m-1; j >= 1; j--)
            if(a[i][j] != a[i][j+1])
                r[i][j] = r[i][j+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(i != 1 && a[i][j] != a[i-1][j]){
                up[i][j] = up[i-1][j] + 1;
                l[i][j] = max(l[i-1][j], l[i][j]);
                r[i][j] = min(r[i-1][j], r[i][j]);
            }
            int A = r[i][j] - l[i][j] + 1;
            int B = up[i][j] + 1;
            ans1 = max(ans1, min(A, B) * min(A, B));
            ans2 = max(ans2, A * B);
        }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}