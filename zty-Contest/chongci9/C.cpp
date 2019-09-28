#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
int k, n, e[N], num1[N], num2[N];
int ans, q1[N], l1, l2, r1, r2, q2[N], p;
int main() {
    scanf("%d %d", &k, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &e[i]);
    l1 = l2 = 1;
    for(int i = 1; i <= n; i++) {

        while(abs(q1[l1] - e[i]) > k && l1 <= r1) p = num1[l1++];
        while(e[i] <= q1[r1] && l1 <= r1) r1--;
        num1[++r1] = i;
        q1[r1] = e[i];

        while(num1[l1] < p && l1 <= r1)l1++;
        while(num2[l2] < p && l2 <= r2)l2++;

        while(abs(q2[l2] - e[i]) > k && l2 <= r2) p = num2[l2++];
        while(e[i] >= q2[r2] && l2 <= r2) r2--;
        num2[++r2] = i;
        q2[r2] = e[i];

        while(num1[l1] < p && l1 <= r1)l1++;
        while(num2[l2] < p && l2 <= r2)l2++;
      // cout<<i<<' '<<p<<endl;
      //  cout<< abs(i - p)<<endl;
        ans = max(ans , abs(i - p));
    }
    printf("%d\n", ans);
    return 0;
}