#include<bits/stdc++.h>
using namespace std;
int n,m,s,x,y,t;
const int N = 500010;
int h[N],cnt,to[N<<1],nxt[N<<1];
void add_edge(int u,int v){
    to[++cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
queue<int>q;
int d[N],F[N][25];
void bfs(int from){
    d[from]=1;q.push(from);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=h[x];i;i=nxt[i]){
            int y=to[i];
            if(d[y])continue;
            d[y]=d[x]+1;
            F[y][0]=x;
            for(int j=1;j<=t;j++)
                F[y][j]=F[F[y][j-1]][j-1];
            q.push(y);
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    for(int i=t;i>=0;i--)
        if(d[F[y][i]]>=d[x])y=F[y][i];
    if(x==y)return x;
    for(int i=t;i>=0;i--)
        if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
    return F[x][0];
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
int main(){
    n=read();m=read();s=read();
    t=(int)(log(n)/log(2))+1;
    for(int i=1;i<=n-1;i++){
        x=read();y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    bfs(s);
    for(int i=1;i<=m;i++){
        x=read();y=read();
        printf("%d\n",lca(x,y));
    }
    return 0;
}