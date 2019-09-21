#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
int r,n,d,T,m;
const double eps = 1e-8;
double A[N][N];
void Gauss(){
    n--;
    for(int i=0;i<n;i++){
        r=i;
        for(int j=i+1;j<n;j++)
            if(fabs(A[j][i])>fabs(A[r][i]))r=j;
        if(fabs(A[r][i])<eps){printf("0\n");return;}
        if(r!=i)for(int j=i;j<=n;j++)swap(A[i][j],A[r][j]);
        for(int k=i+1;k<n;k++){
            double f=A[k][i]/A[i][i];
            for(int j=i;j<=n;j++)A[k][j]-=A[i][j]*f;
        }
    }
    double ans=1;
    for(int i=0;i<n;i++)ans=ans*A[i][i];
    printf("%.0f\n",abs(ans));
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(A,0,sizeof(A));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            A[x][x]++;A[y][y]++;
            A[x][y]--;A[y][x]--;
        }
        Gauss();
    }
    return 0;
}