#include<bits/stdc++.h>
using namespace std;
const int N = 800010;
int n,m;
int h[N],nxt[N],e[N],to[N],cnt;
void add_edge(int u,int v,int w){
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; e[cnt] = w; to[cnt] =v;
}
int d[N],vis[N],tot;
int spfa(){
    for(int i = 1; i <= n; i++) d[i] = 0x3f3f3f3f;
    d[0] = 0;
    vis[0] = 1;
    deque<int>q;
    q.push_front(0);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        vis[u] = 0;
        for(int i = h[u]; i; i=nxt[i]){
            int v = to[i];
            if(d[v] > d[u] + e[i]){
                d[v] = d[u] + e[i];
                if(!vis[v]){
                    vis[v]=1;
                    tot++;
                    if(!q.empty() && d[v] < d[q.front()])
                        q.push_front(v);
                    else q.push_back(v);
                }
            }
            if(tot > 300000)return -1;
        }
    }
    return d[n];
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m; i++) {
        int l,r;
        scanf("%d %d",&l,&r);
        add_edge(l-1,r,1);
        add_edge(r,l-1,-1);
    }
    for(int i = 1; i <= n ;i++){
        add_edge(i,i-1,0);
        add_edge(i-1,i,1);
    }
    printf("%d\n",spfa());
    return 0;
}