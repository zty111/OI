#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, rr, c, p[N];
bool check(int x) {
    int l = 1, r = c, cnt = 0;
    while(r <= n) {
        if(p[r] - p[l] <= x) {
            cnt++;
            l = r + 1;
            r = l + c - 1;
        } else {
            l++; r++;
        }
    }
    return cnt >= rr;
}
int main() {
    scanf("%d %d %d", &n, &rr, &c);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    sort(p+1, p+1+n);
    int l = 0, r = p[n], ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}