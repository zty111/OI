#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30;
int n;
double a[N][N],b[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++){
            scanf("%lf",&b[i][j]);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            a[i][j]=2*(b[i+1][j]-b[i][j]);
            a[i][n+1]+=(b[i+1][j]*b[i+1][j]-b[i][j]*b[i][j]);
        }
    for(int i=1;i<=n;i++){
        int r=i;
        for(int j=i+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;
        if(r!=i)for(int j=i;j<=n+1;j++)swap(a[i][j],a[r][j]);
        for(int k=i+1;k<=n;k++){
            double f=a[k][i]/a[i][i];
            for(int j=i;j<=n+1;j++)a[k][j]-=a[i][j]*f;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++)
            a[i][n+1]-=a[j][n+1]*a[i][j];
        a[i][n+1]/=a[i][i];
    }
    for(int i=1;i<=n;i++){
        printf("%.3f ",a[i][n+1]);
    }
    return 0;
}