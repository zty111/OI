#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 300;
int w,n,m,x[N],y[N],T,cnt,s,t;
long long dis[N][N];
struct panzi{
    int r,c;
}p[N];
struct point{
    int x,y;
    point(int x,int y):x(x),y(y){}
};
struct Edge{
    point from,to;
    int dist;
    Edge(point u,point v,int w):from(u),to(v),dist(w){}
};
vector<Edge>edges;
vector<int>G[N][N];
bool cmpb(panzi A,panzi B){if(A.r==B.r)return A.c<B.c;else return A.r>B.r;}
bool cmps(panzi A,panzi B){return A.r<B.r;}
bool operator <(const point A,const point B){
    return A.x<B.x;
}
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
void add_edge(point A,point B,int cost){
    edges.push_back(Edge(A,B,cost));
    int mm=edges.size();
    G[A.x][A.y].push_back(mm-1);
}
typedef pair<int,point> pii;
bool done[N][N];
int d[N][N];
void dijkstra(point a)
{
    priority_queue<pii,vector<pii>,greater<pii> > q;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=cnt;j++)
            d[i][j]=inf;
    d[a.x][a.y]=0;
    memset(done,0,sizeof(done));
    q.push(make_pair(0,a));;
    while(!q.empty())
    {
        pii x=q.top();q.pop();
        point u=x.second;
        if(done[u.x][u.y])continue;
        done[u.x][u.y]=1;
        for(int j=0;j<int(G[u.x][u.y].size());j++)
        {
            Edge& e=edges[G[u.x][u.y][j]];
            if(d[u.x][u.y]+e.dist<d[e.to.x][e.to.y])
            {
                d[e.to.x][e.to.y]=d[u.x][u.y]+e.dist;
                q.push(make_pair(d[e.to.x][e.to.y],e.to));
            }
        }
    }
}
int main(){
    T=read();
    while(T--){
        n=read();m=read();w=read();
        for(int i=1;i<=n;i++){
            x[i]=read();y[i]=read();
        }
        for(int i=1;i<=m;i++){
            p[i].r=read();p[i].c=read();   
        }
        //预处理没用的盘子
        sort(p+1,p+1+m,cmpb);
        int now=inf;cnt=0;
        for(int i=1;i<=m;i++)
            if(p[i].c<now)p[++cnt]=p[i],now=p[cnt].c;
        sort(p+1,p+1+cnt,cmps);
        //预处理距离
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=sqrt(1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]));
        for(int i=1;i<=n;i++)
            dis[0][i]=y[i];
        for(int i=1;i<=n;i++)
            dis[i][n+1]=w-y[i];
        //清空图
        s=0;t=n+1;
        for(int i=s;i<=t;i++)
            for(int j=1;j<=cnt;j++)
                G[i][j].clear();
        G[s][0].clear();G[t][0].clear();
        edges.clear();
        //加边O(n*n*n)
        s=0;t=n+1;
       // int times=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)if(i!=j){
                int k2=cnt;//k1up k2down O(1) 单调栈
                for(int k=1;k<=cnt;k++){
                    while(k2>=1&&dis[i][j]<p[k].r+p[k2].r)k2--;//,times;
                    if(k2+1<=cnt)add_edge(point(i,k),point(j,k2+1),p[k2+1].c);
                }
            }
        //cout<<times<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<cnt;j++)
                add_edge(point(i,j),point(i,j+1),p[j+1].c-p[j].c);
        for(int i=1;i<=n;i++){
            int k=1;
            while(k<=cnt&&dis[s][i]>p[k].r)k++;
            if(k<=cnt)add_edge(point(s,0),point(i,k),p[k].c);
        }
        for(int i=1;i<=n;i++)
            for(int k=1;k<=cnt;k++)
                if(dis[i][t]<=p[k].r)
                    add_edge(point(i,k),point(t,0),0);
        //cout<<edges.size()<<endl;
        //最短路
        dijkstra(point(s,0));
        int ans=d[t][0];
        if(ans==inf)printf("impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}