#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int n, k;
int cnt, nxt[N], h[N], e[N], to[N];
void add_edge(int u, int v, int w){
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; e[cnt] = w; to[cnt] = v;
}
int d[N], vis[N], c[N];
bool spfa() {
    deque<int>q;
    vis[0] = 1;
    d[0] = 0;
    q.push_front(0);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        vis[u] = 0;
        for(int i = h[u]; i; i = nxt[i]){
            int v = to[i];
            if(d[v] > d[u] + e[i]){
                d[v] = d[u]+ e[i];
                if(!vis[v]){
                    vis[v] = 1;
                    if(!q.empty() && d[v] < d[q.front()])
                        q.push_front(v);
                    else q.push_back(v);
                    c[v]++;
                    if(c[v] > n)return false;
                }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) {
        int a, b, x;
        scanf("%d %d %d", &x, &a, &b);
        switch(x){
            case 1:
                add_edge(a, b, 0);
                add_edge(b, a, 0);
                break;
            case 2:
                add_edge(a, b, -1);
                break;
            case 3:
                add_edge(b, a, 0);
                break;
            case 4:
                add_edge(b, a, -1);
                break;
            case 5:
                add_edge(a, b, 0);
                break;
        }
    }
    for(int i = n; i >= 1; i--) add_edge(0, i, -1), d[i] = 0x3f3f3f3f;
    if(!spfa())printf("-1\n");
    else{
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            ans -= d[i];
        printf("%lld\n", ans);
    }
    return 0;
}