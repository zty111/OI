#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool id_dfs(int d,int dm,int x,int y){
    if(d>dm)return false;
    if(y>x&&(dm-d<=23&&(x<<(dm-d))<y))return false;
    if(y<x&&x-(dm-d)>y)return false;
    if(x==y)return true;
    if(id_dfs(d+1,dm,(x<<1),y))return true;
    if(id_dfs(d+1,dm,x+1,y))return true;
    if(id_dfs(d+1,dm,x-1,y))return true;
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    if(n>m)ans=n-m;
    else{
        int longen=m-n;
        for(int i=1;i<=longen;i++){
            if(id_dfs(0,i,n,m)){ans=i;break;}
        }
    }
    printf("%d\n",ans);  
    return 0;
}