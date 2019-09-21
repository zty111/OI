#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int h[N], nxt[N], cnt, e[N], to[N];
void add_edge(int u, int v, int w) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; e[cnt] = w; to[cnt] = v;
}
int dis[N], ins[N];
void spfa(int s){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    queue<int> q;
    ins[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ins[u] = 0;
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[u] + e[i] < dis[v]) {
                dis[v] = dis[u] + e[i];
                if(!ins[v]){
                    q.push(v);
                    ins[v] = 1;
                }
            }
        }
    }
}