#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], r[N], c[N];
bool cmp(int A, int B) {
    return a[A] < a[B];
}
void add(int x,int k){
    for(;x<=n;x+=x&-x)c[x]+=k;
}
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=c[x];
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(m) {
        m = ((m - 1) % 2 + 1) % 2;
        for(int i = 1; i <= n; i++) r[i] = i;
        sort(r + 1, r + 1 + n, cmp);
        for(int i = 1; i <= n; i++) a[i] = r[i];
        /*if(!m) {
            for(int i = 1; i <= n; i++) r[i] = i;
            sort(r + 1, r + 1 + n, cmp);
            for(int i = 1; i <= n; i++) a[i] = r[i];
        }*/
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += ask(a[i] - 1);
        add(a[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}