#include<bits/stdc++.h>
using namespace std;
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
const int N = 100010;
int n,k,a,b,ans;
int head[N],to[N],vis[N],nxt[N],e[N],cnt,d[N];
void add_edge(int u,int v,int d){
    to[++cnt]=v;
    e[cnt]=d;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void bfs(){
    queue<int>q;
    q.push(1);vis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(vis[v])continue;
            vis[v]=1;
            d[v]=d[u]+e[i];
        }
    }
}
int main(){
    n=read();k=read();
    for(int i=1;i<=n-1;i++){
        a=read();b=read();
        add_edge(a,b,1);
        add_edge(b,a,1);
    }
    ans=((n-1)<<1);
    bfs();
    return 0;
}