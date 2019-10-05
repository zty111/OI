#include <bits/stdc++.h>
using namespace std;
int n, m, a[110][110], r[110][110], c[110][110];
int vr[110], vc[110];
long long ans, Ans;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            Ans += a[i][j];
            if(a[i][j]) ans++;
            a[i][0] = max(a[i][0], a[i][j]);
            a[0][j] = max(a[0][j], a[i][j]);
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(a[i][j] && a[i][j] == a[i][0]) r[i][j] = 1;
            if(a[i][j] && a[i][j] == a[0][j]) c[i][j] = 1;
        }
    for(int i = 1; i <= n; i++) if(!vr[i])
        for(int j = 1; j <= m; j++) if(!vc[j])
        {
            if(a[i][j] && r[i][j] && c[i][j]){ 
                vr[i] = vc[j] = 1, ans += a[i][j] - 1;
                break;
            }
            if(vr[i]) break;
        }
    for(int i = 1; i <= n; i++)
        if(a[i][0] && !vr[i]) ans += a[i][0] - 1;
    for(int j = 1; j <= m; j++)
        if(a[0][j] && !vc[j]) ans += a[0][j] - 1;
    printf("%lld\n", Ans - ans);
    return 0;
}