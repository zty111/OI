// p11394 广义菲波那切数列
//[数学]
//矩阵加速
//zty111
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p;
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
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%p)%p;
    return C;
}
void qpow(ll b){
    while(b){
        if(b&1)B=Mul(B,A);
        A=Mul(A,A);
        b>>=1;
    }
}
int main(){
    ll n,a1,a2,pp,q;
    scanf("%lld%lld%lld%lld%lld%lld",&pp,&q,&a1,&a2,&n,&p);
    if(n==1)printf("%lld\n",a1%p);
    else if(n==2)printf("%lld\n",a2%p);
    else{
    e.a[1][1]=e.a[2][2]=1;e.a[1][0]=e.a[0][1]=0;e.x=e.y=2;
    A.a[1][1]=pp;A.a[2][1]=q;A.a[1][2]=1;A.a[2][2]=0;A.x=A.y=2;
    B.a[1][1]=a2;B.a[1][2]=a1;B.x=1;B.y=2;
    qpow(n-2);
    printf("%lld\n",B.a[1][1]);
    }
    return 0;
}