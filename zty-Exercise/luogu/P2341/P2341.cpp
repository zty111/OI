#include<bits/stdc++.h>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
    return x*f;
}
const int N = 100010;
int cnt,to[N],h[N],nxt[N];
void add_edge(int u,int v){
    cnt++;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
vector<int>scc[N];
int num,dfn[N],low[N],s[N],top,ins[N],cnum,c[N];
void tarjan(int x){
    dfn[x]=low[x]=++num;
    s[++top]=x;ins[x]=1;
    for(int i=h[x];i;i=nxt[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(ins[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){
        cnum++;int y;
        do{
            y=s[top--];ins[y]=0;
            c[y]=cnum;
            scc[cnum].push_back(y);
        }while(x!=y);
    }
}
int n,m,du[N];
int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        add_edge(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=h[i];j;j=nxt[j]){
            int v=to[j];
            if(c[v]!=c[i])du[c[i]]++;
        }
    int ans=0,flag=0;
    for(int i=1;i<=cnum;i++){
        if(du[i]==0){
            if(ans)flag=1;
            ans=i;
        }
    }
    if(flag)printf("0\n");
    else printf("%d\n",int(scc[ans].size()));
    return 0;
}