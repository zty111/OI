#include <cstdio>
using namespace std;
int n, a[30];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l1 = 1, l2 = n;
    for(;l1 <= n; l1++) if(!a[l1])break;
    for(;l2 >= 1; l2--) if(!a[l2])break;
    --l1;  l2 = n - l2;
    if((l1 & 1) || (l2 & 1)) printf("YES\n");
    else printf("NO\n");
    return 0;
}