#include<bits/stdc++.h>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    int x=0;char ch=nc();
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
    return x;
}
const int N = 50000;
const int M = 5000000;
int n,h[N],nxt[M],to[M],cnt,from[M];
void add_edge(int u,int v){
    cnt++;to[cnt]=v;from[cnt]=u;nxt[cnt]=h[u];h[u]=cnt;
}
int c[N],dfn[N],low[N],num,in[N],cnum,s[N],top,out[N],ins[N];
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
        cnum++;
        int v;
        do{
            v=s[top--];
            ins[v]=0;
            c[v]=cnum;
        }while(u!=v);
    }
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        int v=read();
        while(v){
            add_edge(i,v);
            v=read();
        }
    }
    for(int i=1;i<=n;i++)if(!dfn[i])
        tarjan(i);
    for(int i=1;i<=cnt;i++){
        int u=from[i],v=to[i];
        if(c[u]!=c[v])in[c[v]]++,out[c[u]]++;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=cnum;i++){
        if(!in[i])ans1++;
        if(!out[i])ans2++;
    }
    ans2=max(ans2,ans1);
    if(cnum==1)ans2=0;
    printf("%d\n",ans1);
    printf("%d\n",ans2);
    return 0;
}