#include<iostream>
using namespace std;
int n,a[10][10],m[10][10];
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(m[i][j])cout<<'/';
            else cout<<'\\';
        cout<<endl;
    }
}
int f[200];
int find(int a){return f[a]==a?a:find(f[a]);}
bool dfs(int x,int y){
    if(y>n){
        if(a[n+1][n+1]>0&&a[n+1][n+1]<=4)return false;
        else {print();return true;}
    }

    int fa=find(x*(n+1)+y);
    int fb=find((x+1)*(n+1)+y+1);
    if(fa!=fb){
        f[fa]=fb;
        bool ok=1;
        m[x][y]=0;
        a[x][y]--;a[x+1][y+1]--;
        if(a[x][y]<0||a[x+1][y+1]<0)ok=0;
        if(a[x][y]>0&&a[x][y]<=4)ok=0;
        if(x==n&&a[x+1][y]>0&&a[x+1][y]<=4)ok=0;
        if(y==n&&a[x][y+1]>0&&a[x][y+1]<=4)ok=0;
        if(ok){
            if(x+1<=n){if(dfs(x+1,y))return true;}
            else if(dfs(1,y+1))return true;
        }
        a[x][y]++;a[x+1][y+1]++;
        f[fa]=fa;
    }
    //
    fa=find((x+1)*(n+1)+y);
    fb=find(x*(n+1)+(y+1));
    if(fa!=fb){
        f[fa]=fb;
        bool ok=1;
        m[x][y]=1;
        a[x+1][y]--;a[x][y+1]--;
        if(a[x+1][y]<0||a[x][y+1]<0)ok=0;
        if(a[x][y]>0&&a[x][y]<=4)ok=0;
        if(x==n&&a[x+1][y]>0&&a[x+1][y]<=4)ok=0;
        if(y==n&&a[x][y+1]>0&&a[x][y+1]<=4)ok=0;
        if(ok){
            if(x+1<=n){if(dfs(x+1,y))return true;}
            else if(dfs(1,y+1))return true;
        }
        a[x+1][y]++;a[x][y+1]++;
        f[fa]=fa;
    }
    return false;
}
char ch;int T;
int main(){
    cin>>T;
    while(T--){
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n+1;j++){
            cin>>ch;
            if(ch=='.')a[i][j]=10;
            else a[i][j]=ch-48;
        }
    for(int i=1;i<=180;i++)
        f[i]=i;
    dfs(1,1);}
    return 0;
}