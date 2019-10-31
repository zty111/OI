#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,m,f[N],a[N];
long long ans;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
priority_queue<int,vector<int>,greater<int>>q[N];
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
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read(),f[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,pu,pv;
        u=read();v=read();
        pu=find(u);pv=find(v);
        f[pu]=pv;
    }
    for(int i=1;i<=n;i++){
        int fa=find(i);
        q[fa].push(a[i]);
    }
    int rt=find(1);
    for(int i=2;i<=n;i++){
        int pi=find(i);
        if(rt!=pi){
            int mr=q[rt].top();q[rt].pop();
            int md=q[pi].top();q[pi].pop();
            ans=ans+mr+md;
            f[pi]=rt;
            while(!q[pi].empty()){q[rt].push(q[pi].top());q[pi].pop();}
        }
    }
    printf("%lld\n",ans);
    return 0;
}