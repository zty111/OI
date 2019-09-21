#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,cnt=1,e[N],to[N],h[N],nxt[N],m,num[N],ans,l,r;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
void add_edge(int u,int v,int w){
    e[++cnt]=w;
    to[cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
vector<int>army;
vector<int>ok;
vector<int>need;
int dis[N],fa[N],have[N];
void dfs(int u){
    for(int i = h[u]; i; i = nxt[i]){
        int v = to[i];
        if(!dis[v]){
            fa[v] = u;
            dis[v] = dis[u] + e[i];
            r += dis[v] * num[v];
            dfs(v);
        }
    }
}
bool cmp(int a,int b){
    return a > b;
}
int vis[N],ne[N];
void dfs2(int u, int topf){
    vis[u] = 1;
    int flag = 1;
    for(int i = h[u]; i; i = nxt[i]){
        int v = to[i];
        if(have[to[i]]||vis[v])continue;
        flag = 0;
        dfs2(v, topf);
        if(ne[topf])return;
    }
    if(flag)ne[topf]=1;
}
bool check(int x) {
    for(int i = 0; i < army.size(); i++) {
        int now = army[i];
        if(dis[now] <= x) {
            int ret = x;
            while(fa[now]!=1 && ret > dis[now] - dis[fa[now]]){
                ret -= dis[now] - dis[fa[now]];
                now = fa[now];
            }
            if(ret > 2 * dis[now]){
                ok.push_back(ret - dis[now]);  
            } 
            else have[now]=1;
        }
        else {
            int ret = x;
            while(ret > dis[now] - dis[fa[now]]){
                ret -= dis[now] - dis[fa[now]];
                now = fa[now];
            }
            have[now]=1;
        }
    }
    sort(ok.begin(),ok.end(),cmp);
    for(int i = h[1]; i; i = nxt[i]){
        int v = to[i];
        if(!have[v])dfs2(v,v);
        if(ne[v])need.push_back(dis[v]);
    }
    sort(need.begin(),need.end(),cmp);
    for(int i = 0; i < need.size(); i++){
        if(i >= ok.size())return false;
        if(ok[i] < need[i])return false;
    }
    return true;
}
int main(){
    n=read();
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    m=read();
    for(int i=1;i<=m;i++){
        int a=read();
        num[a]++;
        army.push_back(a);
    }
    dfs(1);
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) ans = mid, r = mid -1;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}