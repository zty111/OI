#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 300;
int w,n,m,x[N],y[N],T,cnt,anss;
int f[N][N];
bool vis[N];
double dis[N][N];
struct panzi{
    int r,c;
}p[N];
bool cmpb(panzi A,panzi B){return A.r>B.r;}
bool cmps(panzi A,panzi B){return A.r<B.r;}
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
int dfs(int u,int k,int ans){
    vis[u]=1;
    for(int i=1;i<=cnt;i++)
        for(int v=1;v<=n;v++)
            if(!vis[v]&&dis[u][v]<=p[k].r+p[i].r)
                ans=min(ans,p[i].c+dfs(v,i));
    vis[u]=0;
    return ans;
}
int main(){
    T=read();
    while(T--){
        memset(f,0x3f,sizeof(f));
        memset(neww,0,sizeof(neww));
        n=read();m=read();w=read();
        for(int i=1;i<=n;i++){
            x[i]=read();y[i]=read();
        }
        for(int i=1;i<=m;i++){
            p[i].r=read();p[i].c=read();   
        }
        sort(p+1,p+1+n,cmpb);
        int now=inf;cnt=0;
        for(int i=1;i<=n;i++)
            if(p[i].c<now)p[++cnt]=p[i],now=p[cnt].c;
        sort(p+1,p+1+cnt,cmps);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=sqrt(1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]));
        for(int i=1;i<=n;i++)
            dis[0][i]=y[i];
        for(int i=1;i<=n;i++)
            dis[i][n+1]=w-y[i];
        for(int i=1;i<=n;i++)
            for(int k=1;k<=cnt;k++)
                if(dis[i][n+1]<=p[k].r)f[i][k]=0;
        anss=inf;
        for(int k=1;k<=cnt;k++)
            for(int i=1;i<=n;i++)
                if(dis[0][i]<=p[k].r)anss=min(ans,p[k].c+dfs(i,k));
        if(anss==inf)printf("impossible\n");
        else printf("%d\n",anss);
    }
    return 0;
}