#include <bits/stdc++.h>
using namespace std;
int n, b[5010];
struct stick {
    int a, b;
}a[5010];
bool cmp(stick A, stick B){
    if(A.a == B.a)return A.b > B.b;
    return A.a > B.a;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].a, &a[i].b);
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 1; j--){
            if(a[i].b > a[j].b) b[i] = max(b[i], b[j] + 1);
        }
        ans = max(ans, b[i]);
    }
    printf("%d\n", ans + 1);
    return 0;
}