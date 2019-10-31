#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,k,a,b;
int h[N],e[N],to[N],nxt[N],cnt=1,vis[N],d[N],pre[N],ans;
void add_edge(int u,int v,int d){
    to[++cnt]=v;
    e[cnt]=d;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
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
int bfs(int s){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(d,-1,sizeof(d));
    memset(pre,0,sizeof(pre));
    q.push(s);d[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(vis[v])continue;
            vis[v]=1;
            d[v]=d[u]+1;
            pre[v]=i;
            q.push(v);
        }
    }
    int x=1;
    for(int i=2;i<=n;i++)
        if(d[i]>d[x])x=i;
    return x;
}
void dp(int x){
    vis[x]=1;
    for(int i=h[x];i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        dp(v);
        ans=max(ans,d[x]+d[v]+e[i]);
        d[x]=max(d[x],d[v]+e[i]);
    }
}
void change(int u){
    for(;pre[u];u=to[pre[u]^1])
        e[pre[u]]=e[pre[u]^1]=-1;
}
int main(){
    n=read();k=read();
    for(int i=1;i<=n-1;i++){
        a=read();b=read();
        add_edge(a,b,1);
        add_edge(b,a,1);
    }
    int p1=bfs(1);
    int p2=bfs(p1);
    int Ans=d[p2];
    if(k==2){
        change(p2);
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        dp(1);
        printf("%d\n",(n<<1)-Ans-ans);
    }
    else{
        printf("%d\n",((n-1)<<1)-Ans+1);
    }
    return 0;
}