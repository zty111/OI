#include <bits/stdc++.h>
using namespace std;
long long n;
int T;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        int cnt = 0;
        long long nn = n;
        while(nn) {
            cnt++;
            nn /= 10;
        }
        bool ok = 0;
        for(long long i = n - 9 * cnt; i <= n; i++) {
            long long now = i, sum = i;
            while(now){
                sum += now % 10;
                now /= 10;
            }
            if(sum == n){
                printf("%lld\n", i);
                ok = 1;
                break;
            }
        }
        if(!ok) printf("Stupid SiriusRen\n");
    }
    return 0;
}