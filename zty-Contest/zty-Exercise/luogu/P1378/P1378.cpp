#include<bits/stdc++.h>
using namespace std;
int n,x,y,xi,yi,nx[10],ny[10],r[10],Ans;
double d[10][10],dis[10],ans;
const double pi = 3.1415926535;
int main(){
    scanf("%d%d%d%d%d",&n,&x,&y,&xi,&yi);if(x>xi)swap(x,xi);if(y>yi)swap(y,yi);
    for(int i=1;i<=n;i++)scanf("%d%d",&nx[i],&ny[i]),r[i]=i;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        d[i][j]=sqrt((nx[i]-nx[j])*(nx[i]-nx[j])+(ny[i]-ny[j])*(ny[i]-ny[j]));
    for(int i=1;i<=n;i++)d[i][0]=min(min(min(nx[i]-x,xi-nx[i]),ny[i]-y),yi-ny[i]);
    Ans=(xi-x)*(yi-y);
    do{
        for(int i=1;i<=n;i++)dis[i]=0;
        ans=0;
        for(int i=1;i<=n;i++){
            int now=r[i];
            double R=d[now][0];
            for(int j=1;j<=n;j++)if(now!=j&&dis[j]!=0)R=min(R,d[now][j]-dis[j]);
            //需要有油滴后才会拦截其他油滴
            if(R<0)R=0;
            dis[now]=R;
            ans+=R*R*pi;
        }
        Ans=min(Ans,int((xi-x)*(yi-y)-ans+0.5));
    }while(next_permutation(r+1,r+1+n));
    printf("%d\n",Ans);
    return 0;
}