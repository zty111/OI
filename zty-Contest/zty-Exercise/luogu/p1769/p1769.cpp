#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double f[11][2050];
int p[2050][2050];
int n,m;
const double eps = 1e-7;
int main(){
    scanf("%d",&n);m=(1<<n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
    for(int i=1;i<=m;i++)f[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x=ceil((double)j/(1<<(i-1)));
            int y=(x&1)==0?x-1:x+1;
            for(int k=y*(1<<(i-1))-(1<<(i-1))+1;k<=y*(1<<(i-1));k++)
                f[i][j]+=f[i-1][j]*p[j][k]/100*f[i-1][k];
        }
    double maxx=-1;int ans;
    for(int i=1;i<=m;i++)
        if(f[n][i]>maxx+eps){
            maxx=f[n][i];
            ans=i;
        }
    printf("%d\n",ans);
    return 0;
}