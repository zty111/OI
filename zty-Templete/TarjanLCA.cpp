#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int h[N],to[N<<1],nxt[N<<1],cnt;
void add_edge(int u,int v){
    ++cnt;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
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
int n,m,Rt;
vector<int>query[N],query_id[N];
void add_query(int x,int y,int id){
    query[x].push_back(y);query_id[x].push_back(id);
    query[y].push_back(x);query_id[y].push_back(id);
}
int f[N],lca[N],val[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void tarjan(int x){
    val[x]=1;
    for(int i=h[x];i;i=nxt[i]){
        int v=to[i];
        if(val[v])continue;
        tarjan(v);
        f[v]=x;
    }
    int s=query[x].size();
    for(int i=0;i<s;i++){
        int y=query[x][i],id=query_id[x][i];
        if(val[y]==2)lca[id]=find(y);
    }
    val[x]=2;
}
int main(){
    n=read();m=read();Rt=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        if(x==y)lca[i]=x;
        else add_query(x,y,i);
    }
    for(int i=1;i<=n;i++)f[i]=i;
    tarjan(Rt);
    for(int i=1;i<=m;i++)printf("%d\n",lca[i]);
    return 0;
}