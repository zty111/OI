#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;
int n;
ll a[N], b[N], ans, S;
set<ll> s;
map<ll,ll> m;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];
    for(int i = 1; i <= n; i++) {
        if(s.find(a[i]) != s.end())m[a[i]] = 1;
        else s.insert(a[i]);
    }
    for(int i = 1; i <= n; i++)
        if(m[a[i]] == 1){
            ans = ans + b[i];
            S |= a[i];
        }
    for(int i = 1; i <= n; i++) {
        if(m[a[i]] != 1) {
            if(a[i] == 0)continue;
            if((S | a[i]) == S)
                ans = ans + b[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}