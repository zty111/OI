#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int h[N],nxt[N],to[N],cnt;
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
void add_edge(int u,int v){
    cnt++;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
int dfn[N],low[N],num,s[N],ins[N],d[N],cnum,top,c[N],A[N],a[N];
vector<int>scc[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    s[++top]=u;ins[u]=1;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        cnum++;int v;
        do{
            v=s[top--];ins[v]=0;
            c[v]=cnum;
            scc[cnum].push_back(v);
            A[cnum]+=a[v];
        }while(v!=u);
    }
}
int to_c[N],h_c[N],nxt_c[N],cnt_c;
void add_c(int u,int v){
    cnt_c++;to_c[cnt_c]=v;nxt_c[cnt_c]=h_c[u];h_c[u]=cnt_c;
}
int n,m,in[N],dis[N];
int topo(){
    queue<int>q;
    for(int i=1;i<=cnum;i++)
        if(!in[i]){
            dis[i]=A[i];
            q.push(i);
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=h_c[u];i;i=nxt_c[i]){
            int v=to_c[i];
            dis[v]=max(dis[v],dis[u]+A[v]);
            in[v]--;
            if(!in[v])q.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=cnum;i++)ans=max(ans,dis[i]);
    return ans;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        add_edge(u,v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(c[u]==c[v])continue;
            add_c(c[u],c[v]);
            in[c[v]]++;
        }
    printf("%d\n",topo());
    return 0;
}