#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010][1010], c[1010];
int ans1, ans2;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i][0]);
    for(int i = 1; i <= m; i++) scanf("%d", &a[0][i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            a[i][j] = min(a[i][0], a[0][j]);
            ans1 += a[i][j];
        }
    for(int i = 1; i <= n; i++) {
        ans2 += a[i][0];
        c[a[i][0]]++;
    }
    for(int i = 1; i <= m; i++) {
        if(!c[a[0][i]]) ans2 += a[0][i];
        else c[a[0][i]]--;
    }
    printf("%d %d\n", ans2, ans1);
    return 0;
}