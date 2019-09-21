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
const int N = 400010;
typedef pair<int,int> pii;
int n,m,k,d,a[N],safe[N];
int e[N],nxt[N],to[N],h[N],cnt;
priority_queue<pii,vector<pii>,greater<pii> >q;
priority_queue<int>best[N];
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
void dijkstra(){
    for(int i=1;i<=k;i++){
        safe[a[i]]=1;
        best[a[i]].push(0);
        q.push(make_pair(0,a[i]));
    }
    while(!q.empty()){
        pii now=q.top();q.pop();
        if(now.first!=best[now.second].top())continue;
        int u=now.second;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i],w=now.first+e[i];
            if(safe[v])continue;
            if(int(best[v].size())>d){
                if(w<best[v].top()){
                    best[v].pop();
                    best[v].push(w);
                    q.push(make_pair(best[v].top(),v));
                }
            }
            else{
                best[v].push(w);
                if(int(best[v].size())>d)
                    q.push(make_pair(best[v].top(),v));
            }
        }
    }
}
int main(){
    n=read();m=read();k=read();d=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    for(int i=1;i<=k;i++)a[i]=read();
    dijkstra();
    printf("%d\n",int(best[1].size())>d?best[1].top():-1);
    return 0;
}