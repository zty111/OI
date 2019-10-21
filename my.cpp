#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 100010;
int n, p;
long long now, ans[N];
priority_queue<int, vector<int>, greater<int> > q;
struct peo {
    int t, id;
}a[N];
bool cmp(peo a, peo b) {
    if(a.t == b.t) return a.id < b.id;
    return a.t < b.t;
}
int main() {
    scanf("%d", &n);
    scanf("%d", &p);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].t);
        a[i].id = i;
    }
    sort(a+1, a+1+n, cmp);
    int j = 1;
    while(j <= n && a[j].t <= now) q.push(a[j++].id);
    for(int i = 1; i <= n; i++) {
        if(q.empty()) {
            now = a[j].t + p;
            ans[a[j].id] = now;
            j++;
        } else {
            now = now + p;
            int id = q.top(); q.pop();
            ans[id] = now;
        }
        while(j <= n && a[j].t <= now) q.push(a[j++].id);
    }
    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}