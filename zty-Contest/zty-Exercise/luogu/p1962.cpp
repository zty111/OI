// p1962 菲波那切数列
//[数学]
//矩阵加速
//zty111
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1e9+7;
struct Mat{
    ll a[3][3];
    ll x,y;
}e,A,B;
Mat Mul(Mat A,Mat B){
    Mat C;C.x=A.x;C.y=B.y;
    for(int i=1;i<=C.x;i++)
        for(int j=1;j<=C.y;j++)
            C.a[i][j]=0;
    for(int i=1;i<=C.x;i++)
        for(int j=1;j<=C.y;j++)
            for(int k=1;k<=A.y;k++)
                C.a[i][j]=(C.a[i][j]+A.a[k][i]*B.a[j][k]%p)%p;
    return C;
}
Mat qpow(Mat A,ll b){
    Mat ret=e;
    while(b){
        if(b&1)ret=Mul(ret,A);
        A=Mul(A,A);
        b>>=1;
    }return ret;
}
int main(){
    ll n;
    scanf("%lld",&n);
    if(n==1||n==2)printf("1\n");
    else{
    e.a[1][1]=e.a[2][2]=1;e.a[1][0]=e.a[0][1]=0;e.x=e.y=2;
    A.a[1][1]=A.a[2][1]=A.a[1][2]=1;A.a[2][2]=0;A.x=A.y=2;
    A=qpow(A,n-2);
    B.a[1][1]=B.a[1][2]=1;B.x=1;B.y=2;
    B=Mul(A,B);
    printf("%lld\n",B.a[1][1]);
    }
    return 0;
}