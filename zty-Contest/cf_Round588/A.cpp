#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ne = a + b + c + d;
    if(2 * (a + b) == ne || 2 * (a + c) == ne || 2 * (a + d) == ne || 2 * (b + c) == ne || 2 * (b + d) == ne || 2 * (c + d) == ne ||
        2 * a == ne || 2 * b == ne || 2 * c == ne || 2 * d == ne) printf("YES\n");
    else printf("NO\n");
    return 0;
}