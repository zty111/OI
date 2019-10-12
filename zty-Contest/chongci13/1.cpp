#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, s, a[N], l, r, ans, L, R, ans1, ans2;
double S;
int main() {
    scanf("%d %lf", &n, &S);
    int s = floor(S);
    scanf("%d %d", &L, &R);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &l, &r);
        for(int j = l; j <= r; j++) a[j] = 1;
    }
    int now = 0, now1;
    for(int i = L; i <= R; i++) {
        if(!a[i]) {
            if(now == 0) now1 = i;
            now++;
        }
        else now = 0;
        if(ans < now) {
            ans = now;
            ans1 = now1;
            ans2 = i;
        }
    }
    if(ans == 0) printf("0 0\n");
    else printf("%d %d\n", ans1, ans2);
    return 0;
}