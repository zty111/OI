#include <cstdio>
#include <iostream>
using namespace std;
int n, m, ans, f1, f2, flag;
int main() {
    cin>>n>>m; n--; m--;
    if(n < 2 && m % 3 != 0) {
        printf("impossible\n");
        return 0;
    }
    if(m < 2 && n % 3 != 0) {
        printf("impossible\n");
        return 0;
    }
    if(n >= 3) f1 = 1;
    if(m >= 3) f2 = 1;
    ans += (n / 3) * 2; n %= 3;
    ans += (m / 3) * 2; m %= 3;
    if(m && (!f1)) ans += 2;
    if(n && (!f2)) ans += 2;
    printf("%d\n", ans + m + n);
    return 0;
}