#include<bits/stdc++.h>
using namespace std;
const int N = 40010;
int h[N],nxt[N],e[N],cnt,to[N];
void add_edge(int u, int v, int w) {
    cnt++; nxt[cnt]=h[u]; h[u]=cnt; e[cnt]=w; to[cnt]=v;
}
int d[N],vis[N],c[N],n;
bool spfa(){
    deque<int>q;
    for(int i = 1; i <= n; i++)
        d[i] = 0x3f3f3f3f;
    q.push_front(0);  
    d[0] = 0;
    vis[0] = 1;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        vis[u] = 0;
        for(int i = h[u]; i; i=nxt[i]){
            int v = to[i];
            if(d[v] > d[u] + e[i]){
                d[v] = d[u] + e[i];
                if(!vis[v]){
                    vis[v] = 1;
                    if(!q.empty() && d[v] < d[q.front()]) // slf优化
                        q.push_front(v);
                    else q.push_back(v);
                }
                c[v]++;
            }
            if(c[v] > n)return false;
        }
    }
    return true; 
}
int main() {
    int m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        add_edge(0,i,0);
    for(int i = 1; i <= m; i++){
        int opt,a,b,c;
        scanf("%d",&opt);
        switch(opt){
        case 1:
            scanf("%d %d %d",&a,&b,&c);
            add_edge(a,b,-c);
            break;
        case 2:
            scanf("%d %d %d",&a,&b,&c);
            add_edge(b,a,c);
            break;
        case 3:
            scanf("%d %d",&a,&b);
            add_edge(a,b,0);
            add_edge(b,a,0);
            break;
        }
    }
    if(spfa())printf("Yes\n");
    else printf("No\n");
    return 0;
}