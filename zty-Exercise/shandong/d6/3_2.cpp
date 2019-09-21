#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 400010;
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
int s,vis[N],fa[N],h[N],to[N],nxt[N],cnt=1,e[N];
ll d[N],ans;
void spfa(){
    queue<int>q;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    vis[s]=1;q.push(s);d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(d[v]>d[u]+e[i]){
                d[v]=d[u]+e[i];
                fa[v]=e[i];
                if(!vis[v])q.push(v),vis[v]=1;
            }
            else if(d[v]==d[u]+e[i]){
                if(fa[v]>e[i])fa[v]=e[i];
            }
        }
    }
}
void add_edge(int u,int v,int w){
    e[++cnt]=w;
    to[cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
int n,m;
int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    s=read();
    spfa();
    for(int i=1;i<=n;i++)ans=ans+fa[i];
    printf("%lld\n",ans);
    return 0;
}