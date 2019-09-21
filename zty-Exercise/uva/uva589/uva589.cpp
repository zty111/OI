#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
//(1,1)(1,M)
//(N,1)(N,M)
const int dx[4]={0,0,1,-1};//东西南北
const int dy[4]={1,-1,0,0};
const char C[4]={'E','W','S','N'};//箱子移动
const char c[4]={'e','w','s','n'};//人移动
const int fan_dir[4]={1,0,3,2};
const int inf = 0x3f3f3f3f;
int n,m,sx,sy,bx,by,tx,ty,boxx,boxy;
int f_box[25][25][4],f_man[25][25][4],d[25][25];
char map[25][25];
bool vis[25][25],var[25][25][4];
struct b_m{
    int x,y,dir;
    b_m(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir){}
}Ans[25][25][4];
bool check(int x,int y){
    if(map[x][y]=='#')return false;
    if(x==boxx&&y==boxy)return false;
    return true;
}
int bfs_m(int fx,int fy,int tx,int ty){
    if(fx==tx&&fy==ty)return 0;
    memset(vis,0,sizeof(vis));
    queue<pair<int,int> >q;
    q.push(make_pair(fx,fy));
    vis[fx][fy]=1;d[fx][fy]=0;
    while(q.size()){
        pair<int,int>now=q.front();q.pop();
        for(int i=0;i<=3;i++){
            int tox=now.first+dx[i],toy=now.second+dy[i];
            if(vis[tox][toy])continue;
            vis[tox][toy]=1;
            if(check(tox,toy)){
                d[tox][toy]=d[now.first][now.second]+1;
                if(tox==tx&&toy==ty)return d[tx][ty];
                q.push(make_pair(tox,toy));
            }
        }
    }return inf;
}
int bfs_f(){
    for(int i=0;i<=3;i++){
        memset(var,0,sizeof(var));
        memset(f_man,0,sizeof(f_man));
        memset(f_box,0,sizeof(f_box));
        queue<b_m>q;
        q.push(b_m(bx,by,i));
        boxx=bx;boxy=by;
        var[bx][by][i]=1;
        f_man[bx][by][i]=bfs_m(sx,sy,bx+dx[i],by+dy[i]);
        while(q.size()){
            b_m now=q.front();q.pop();
            boxx=now.x;boxy=now.y;
            int nx=now.x+dx[now.dir],ny=now.y+dy[now.dir];
            for(int k=0;k<=3;k++){
                int tox=now.x-dx[k],toy=now.y-dy[k];
                int ix=now.x+dx[k],iy=now.y+dy[k],idir=fan_dir[k];
                if(var[ix][iy][idir])continue;
                var[ix][iy][idir]=1;
                if((!check(ix,iy))||(!check(tox,toy)))continue;
                int manD=bfs_m(nx,ny,tox,toy);
                if(manD==inf)continue;
                f_man[ix][iy][idir]=f_man[now.x][now.y][now.dir]+manD;
                f_box[ix][iy][idir]=f_box[now.x][now.y][now.dir]+1;
                if(tx==ix&&ty==iy){
                    //ans
                }
                q.push(b_m(ix,iy,k));
            }
        }
    }
}
int main(){
    while(cin>>n>>m&&n&&m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
                if(map[i][j]=='S')sx=i,sy=j;
                if(map[i][j]=='B')bx=i,by=j;
                if(map[i][j]=='T')tx=i,ty=j;
            }
        
    }
    return 0;
}