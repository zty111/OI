#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],r[1010],c[1010],n,m;
const int mod = 1e9 + 7;
int ans;
void dfs(int x, int y) {
    if(x > n || y > m || x < 1 || y < 1) return;
    a[x][y] = 1;
    
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= r[i]; j++)
            a[i][j] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= c[i]; j++)
            a[j][i] = 1;
        if(a[c[i] + 1][i]){printf("0\n"); return 0;}
    }
    for(int i = 1; i <= n; i++)
        if(a[i][r[i] + 1]){printf("0\n"); return 0;}
    dfs(n,m);
    printf("%d\n", ans);
    return 0;
}