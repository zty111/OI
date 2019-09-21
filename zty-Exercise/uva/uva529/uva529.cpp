#include<iostream>
#include<cstdio>
using namespace std;
int n,A[200];
bool Idfs(int dep,int maxd){
    if(dep>maxd)return false;
    for(int i=dep-1;i>=1;i--)
        for(int j=dep-1;j>=1;j--){
            A[dep]=A[i]+A[j];
            if(A[dep]*(1<<(maxd-dep))<n)return false;
            if(A[dep]==n)return true;
            if(A[dep]>n)continue;
            if(Idfs(dep+1,maxd))return true;
        }
    return false;
}
int main(){
    while(scanf("%d",&n)==1&&n){
        A[1]=1;
        if(n==1)printf("1\n");
        else for(int i=2;i<=145;i++)
            if(Idfs(2,i)){
                for(int j=1;j<=i-1;j++)
                    printf("%d ",A[j]);
                printf("%d",A[i]);
                printf("\n");
                break;
            }
    }
    return 0;
}