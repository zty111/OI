#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,y,xx,yy,a,b;
    scanf("%d %d %d %d", &x, &y, &xx, &yy);
    scanf("%d %d", &a, &b);
    int sy = abs(yy - y), sx = abs(xx - x), flag = 1;
    if(sy % b != 0 || sx % a != 0) flag = 0;
    else if(sy / b % 2 == sx / a % 2) flag = 1;
    else flag = 0;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}