#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], c[N];
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
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += ask(a[i] - 1);
        add(a[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}