#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int m, s, t, d[N];
int main() {
    scanf("%d %d %d", &m, &s, &t);
    for(int i = 1; i <= t; i++)
        if(m >= 10) d[i] = d[i-1] + 60, m -= 10;
        else d[i] = d[i-1], m += 4;
    for(int i = 1; i <= t; i++) {
        d[i] = max(d[i], d[i-1] + 17);
        if(d[i] > s) {printf("Yes\n%d\n", i); return 0;}
    }
    printf("No\n%d\n", d[t]);
    return 0;
}