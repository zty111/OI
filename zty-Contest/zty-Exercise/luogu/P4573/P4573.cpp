#include<bits/stdc++.h>
using namespace std;
int a[10][10],n1,n2;
bool op1[10][10],op2[10][10];
bool hang[10][10],lie[10][10],gong[10][10];
char ch;
const int r[10]={0,0,1,2,0,3,4,0,5,6};
bool check(int i,int x,int y){
    if(x!=1&&x!=4&&x!=7){
        if(op1[y][r[x]]){
            if(i>a[x-1][y])return false;
        }
        else if(i<a[x-1][y])return false;
    } 
    if(y!=1&&y!=4&&y!=7){
        if(op2[r[y]][x]){
            if(i>a[x][y-1])return false;
        }
        else if(i<a[x][y-1])return false;
    } 
    return true;
}
void dfs(int x,int y){
    if(y==10){
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++)
                printf("%d ",a[j][i]);
            printf("\n");
        }
        exit(0);
    }
    int g=((x-1)/3+1)+((y-1)/3)*3;
    for(int i=1;i<=9;i++){
        if(hang[x][i]||lie[y][i]||gong[g][i])continue;
        if(check(i,x,y)==false)continue;
        a[x][y]=i;
        hang[x][i]=lie[y][i]=gong[g][i]=1;
        if(x==9)dfs(1,y+1);
        else dfs(x+1,y);
        a[x][y]=0;
        hang[x][i]=lie[y][i]=gong[g][i]=0;
    }
}
int main(){
    for(int i=1;i<=15;i++){
        cin>>ch;
        if(ch=='>'||ch=='<'){
            n1++;op1[n1][1]=(ch=='>'?1:0);
            for(int j=2;j<=6;j++){
                cin>>ch;
                op1[n1][j]=(ch=='>'?1:0);
            }}
        else{
            n2++;op2[n2][1]=(ch=='v'?1:0);
            for(int j=2;j<=9;j++){
                cin>>ch;
                op2[n2][j]=(ch=='v'?1:0);
            }}
    }
    dfs(1,1);
    return 0;
}