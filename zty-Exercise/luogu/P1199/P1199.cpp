#include <cstdio>
#include <iostream>
using namespace std;
const int N = 505;
int n, a[N][N], b[N], c[N], ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    for(int i = 1; i <= n; i++) {
        b[i] = c[i] = 0;
        for(int j = 1; j <= n; j++) {
            if(a[i][j] > b[i]) c[i] = b[i], b[i] = a[i][j];
            else if(a[i][j] > c[i]) c[i] = a[i][j];
        }
        ans = max(ans, c[i]);
    }
    printf("1\n%d", ans);
    return 0;
}