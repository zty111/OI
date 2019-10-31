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
const int N = 20100;
int n,p,k,sum,ans,l,r;
int head[N],to[N],vis[N],nxt[N],e[N],cnt,v[N],d[N];
void add_edge(int u,int v,int d){
    to[++cnt]=v;
    e[cnt]=d;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
bool check(int x){
    for(int i=1;i<=cnt;i++)
        if(e[i]>x)v[i]=1;
        else v[i]=0;
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    deque<int>q;
    q.push_front(1);
    d[1]=0;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int vv=to[i];
            d[vv]=min(d[vv],d[u]+v[i]);
            if(v[i])q.push_back(vv);
            else q.push_front(vv);
        }
        if(vis[n])return d[n]<=k;
    }
    printf("-1\n");
    exit(0);
}
int main(){
    n=read();p=read();k=read();
    for(int i=1;i<=p;i++){
        int a,b,d;
        a=read();b=read();d=read();
        add_edge(a,b,d);
        add_edge(b,a,d);
        r=max(r,d);
    }
    while(l<=r){
        int mid=(r+l)>>1;
        if(check(mid)){r=mid-1,ans=mid;}
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}