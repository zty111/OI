#include <bits/stdc++.h>
using namespace std;
unsigned long long ans;
const int Ans[] = {1,9,41,109,205};
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        if(n >= 5)
        ans = 325 + 1ull * (n - 5) * (120 - 56 + 14ull * n);
        else ans = Ans[n];
        cout<<ans<<endl;
    }
    return 0;
}