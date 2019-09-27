#include <bits/stdc++.h>
using namespace std;
int n,a1,a2,b1,b2;
const double PI = 3.1415926;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        if(a1 < b1) swap(a1, b1); // a > b
        if(a2 < b2) swap(a2, b2);
        int s1 = a1 * b1, s2 = a2 * b2;
        if(s1 < s2) swap(a1, a2), swap(b1, b2); // 1 > 2
        int flag = 0;
        if(a1 >= a2 && b1 >= b2) printf("Yes\n");
        else{
            for(double d = 0; d <= PI / 2.0; d += 0.01) {
                if(a2 * sin(d) + b2 * cos(d) <= b1 && a2 * cos(d) + b2 * sin(d) <= a1) {
                    flag = 1;
                    break;
                }
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}