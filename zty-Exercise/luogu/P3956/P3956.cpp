#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,c,a[105][105];
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
struct np{
    int x,y,v,d;
    bool operator < (const np A)const {return d>A.d;}
    np(int x,int y,int v,int d):x(x),y(y),v(v),d(d){}
};
int d[105][105];
bool vis[105][105];
void bfs(){
    memset(d,0x3f,sizeof(d));d[1][1]=0;
    priority_queue<np>Q;//normal is >
    Q.push(np(1,1,-2,0));
    while(Q.size()){
        np top=Q.top();Q.pop();
        if(vis[top.x][top.y])continue;
        vis[top.x][top.y]=1;
        for(int i=0;i<=3;i++){
            int tx=top.x+dx[i],ty=top.y+dy[i];
            if(tx<1||tx>m||ty<1||ty>m)continue;
            if(a[tx][ty]==-1&&top.v!=-2)continue;
            int td,v=-2;
            if(a[tx][ty]==-1)td=d[top.x][top.y]+2,v=a[top.x][top.y];
            else if(a[tx][ty]==a[top.x][top.y]||top.v==a[tx][ty])td=d[top.x][top.y];
            else td=d[top.x][top.y]+1;
            if(td<d[tx][ty]){
                d[tx][ty]=td;
                Q.push(np(tx,ty,v,td));
            }
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&c);
        a[x][y]=c;
    }
    bfs();
    if(d[m][m]==0x3f3f3f3f)printf("-1\n");
    else printf("%d\n",d[m][m]);
    return 0;
}