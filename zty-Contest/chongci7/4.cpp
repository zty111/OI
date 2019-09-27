#include <bits/stdc++.h>
using namespace std;
int T, n, m;
long long a[500010], b[500010], la[500010];
int main() {
    scanf("%d", &T);
    while(T--) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(la,0,sizeof(la));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        int now = 1;
        long long ans = 0, Ans = 0;
        for(int i = 1; i <= m; i++){
            a[now] -= i;
            ans += i;
            now++;
            if(now == n + 1){
                Ans = ans;
                now = 1;
                for(int j = 1; j <= n; j++)
                    b[j] = a[j],la[j] = i - n + j;
            }
        }
        now = n;
        for(int j = m; j >= 1; j--) {
            if(j <= la[now])break;
            if(b[now] + la[now] >= j){
                b[now] = b[now] + la[now] - j;
                Ans += j - la[now];
                la[now] = la[now] - n;
                now--;
            }
            if(now == 0) now = n;
        }
        printf("%lld\n", Ans);
    }
    return 0;
}