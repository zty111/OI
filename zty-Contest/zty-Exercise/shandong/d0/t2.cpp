#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,tx,ty,a[1010][1010],d[1010][1010];
typedef pair<int,int> pii;
queue<pii>q;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
void bfs(){
    memset(d,-1,sizeof(d));
    d[sx][sy]=0;
    q.push(make_pair(sx,sy));
    while(q.size()){
        pii u=q.front();q.pop();
        for(int i=0;i<=3;i++){
            int tox=u.first+dx[i];
            int toy=u.second+dy[i];
            if(tox>n||tox<1||toy>n||toy<1||a[tox][toy])continue;
            if(d[tox][toy]==-1){
                d[tox][toy]=d[u.first][u.second]+1;
                q.push(make_pair(tox,toy));
            }
        }   
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    bfs();
    printf("%d\n",d[tx][ty]);
    return 0;
}