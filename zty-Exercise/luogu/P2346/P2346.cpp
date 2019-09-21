#include<bits/stdc++.h>
using namespace std;
char ch;
int a[5][5];
bool check(){
    int k=a[1][1];if(a[2][2]==k&&a[3][3]==k&&a[4][4]==k)return true;
    k=a[1][4];if(a[2][3]==k&&a[3][2]==k&&a[4][1]==k)return true;
    for(int i=1;i<=4;i++){
        k=a[i][1];if(a[i][2]==k&&a[i][3]==k&&a[i][4]==k)return true;
    }
    for(int i=1;i<=4;i++){
        k=a[1][i];if(a[2][i]==k&&a[3][i]==k&&a[4][i]==k)return true;
    }
    return false;
}
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
bool ID_DFS(int d,int maxd,int color){
    if(d==maxd){
        if(check())return true;
        else return false;
    }
    for(int x=1;x<=4;x++)for(int y=1;y<=4;y++){
        if(a[x][y])continue;
        for(int i=0;i<=3;i++){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>4||tx<1||ty>4||ty<1)continue;
            if(color!=-1)if(color==a[tx][ty])continue;
            swap(a[x][y],a[tx][ty]);
            if(ID_DFS(d+1,maxd,a[x][y]))return true;
            swap(a[x][y],a[tx][ty]);
        }
    }
    return false;
}
int main(){
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++){
            cin>>ch;
            if(ch=='B')a[i][j]=1;
            else if(ch=='W')a[i][j]=2;
            else a[i][j]=0;
        }
    int ans=1;
    while(ID_DFS(0,ans,-1)==false)ans++;
    cout<<ans<<endl;
    return 0;
}