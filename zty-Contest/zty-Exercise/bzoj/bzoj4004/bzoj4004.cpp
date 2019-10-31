#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n,m,c[N];
long double a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%Lf",&a[i][j]);
        }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int cnt=0,ans=0;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++)
            if(fabs(a[j][i])>1e-6)
            if(c[j]<c[i])
            {
                swap(c[i],c[j]);
                swap(a[i],a[j]);
            }
        if(fabs(a[i][i])<=1e-6)continue;
        else {cnt++;ans+=c[i];}
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            long double rate=a[j][i]/a[i][i];
            for(int k=i;k<=m;k++)a[j][k]-=a[i][k]*rate;
        }
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}