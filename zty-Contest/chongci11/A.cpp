#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
struct tree {
    int p, l, r, h;
}A[N];
int n;
double ans;
bool cmp(tree A, tree B) {
    return A.l < B.l;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &A[i].p, &A[i].h);
        A[i].l = A[i].p - A[i].h;
        if(A[i].l < 0){
            printf("-1\n");
            return 0;
        }
        A[i].r = A[i].p + A[i].h;
    }
    sort(A + 1, A + 1 + n, cmp);
    int now = 0, la = 0;
    for(int i = 1; i <= n; i++) {
        if(A[i].r <= la) continue;
        if(A[i].l >= la) now = A[i].r - A[i].l;
        else now += A[i].r - la;
        la = A[i].r;
        ans = max(ans, (double)now / 2.0);
    }
    printf("%.1f\n", ans);
    return 0;
}