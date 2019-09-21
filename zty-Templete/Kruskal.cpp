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
const int N = 200010;
int r[N],e[N],to[N],from[N],cnt,f[N];
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;from[cnt]=u;
}
bool cmp(int a,int b){
    return e[a]<e[b];
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int kruskal(){
    int ans=0;
    for(int i=1;i<=cnt;i++){
        int fu=find(from[r[i]]),fv=find(to[r[i]]);
        if(fu!=fv){
            ans+=e[r[i]];
            f[fu]=fv;
        }
    }
    return ans;
}
int n,m;
int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        add_edge(u,v,w);
    }
    for(int i=1;i<=cnt;i++)r[i]=i;
    for(int i=1;i<=n;i++)f[i]=i;
    sort(r+1,r+1+cnt,cmp);
    printf("%d\n",kruskal());
    return 0;
}