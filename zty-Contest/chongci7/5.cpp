#include <bits/stdc++.h>
using namespace std;
long long n,m,T;
const int N = 501000;
long long a[N],b[N],la[N];
int main() {
    scanf("%lld", &T);
    while(T--) {
    memset(b,0,sizeof(b));
    memset(la,0,sizeof(la));
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    int now = 1, cnt = 0;
    for(long long i = 1; i <= m; i++) {
        if(b[now] + i > a[now])break;
        now = now + 1;
        if(now == n + 1){
            for(int j = 1; j <= n; j++)
                b[j] += i - n + j, la[j] = i - n + j;
            now = 1;
            cnt++;
        }
    }
    now = n;
    for(long long i = m; i >= 1; i--) {
        if(i <= la[now])break;
        if(!cnt)break;
        if(b[now] - la[now] + i <= a[now]) {
            b[now] = b[now] - la[now] + i;
            la[now] = la[now] - n;
            now--;
            if(now == 0) now = n, cnt--;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += b[i];
    printf("%lld\n", ans);
    }
    return 0;
}