#include <bits/stdc++.h>
using namespace std;
int r[10][10], c[10][10], a[10][10], n;
int v[10][10], num[100], id[10][10], cnt, tim[100];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void dfs1(int x, int y, int col) {
    if(x < 1 || x > n || y < 1 || y > n) return;
    id[x][y] = col; tim[col]++;
    for(int i = 0; i < 4; i++) {
        int tox = x + dx[i], toy = y + dy[i];
        if(!id[tox][toy] && a[tox][toy] == a[x][y]) dfs1(tox, toy, col);
    }
}
int ans[10][10], Ans;
void dfs2(int x, int y) {
    if(x > n) {
        Ans++;
        if(Ans == 1)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans[i][j] = v[i][j];
    }
    for(int i = 1; i <= n; i++) {
        if(r[x][i] || c[i][y]) continue;
        if(a[x][y] % i != 0) continue;
        if(a[x][y] % (num[id[x][y]] * i) != 0) continue;
        if(tim[id[x][y]] == 1 && i * num[id[x][y]] != a[x][y]) continue;
        r[x][i] = c[i][y] = 1;
        v[x][y] = i; num[id[x][y]] *= i;
        tim[id[x][y]]--;
        if(y != n) dfs2(x, y + 1);
        else dfs2(x + 1, 1);
        tim[id[x][y]]++;
        r[x][i] = c[i][y] = 0;
        v[x][y] = 0; num[id[x][y]] /= i;
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!id[i][j]) dfs1(i, j, ++cnt);
    for(int i = 1; i <= cnt; i++) num[i] = 1;
    dfs2(1, 1);
    printf("%d\n", Ans);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}