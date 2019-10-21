#include <cstdio>
using namespace std;
const int N = 1005;
int vis[N][N], cnt[N], n, m, k, x;
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf("%d", &x);
            if(!vis[x][j])
                vis[x][j] = 1, cnt[x]++;
        }
    for(int i = 1; i <= k; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}