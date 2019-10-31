#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,y;
const ll mod=1e8;
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
struct bar{
    ll ch[2][2];
}e;
bar operator * (bar A,bar B){
    bar ret;
    ret.ch[0][0]=ret.ch[0][1]=ret.ch[1][0]=ret.ch[1][1]=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                ret.ch[i][j]=(ret.ch[i][j]+A.ch[i][k]*B.ch[k][j])%mod;
    return ret;
}
bar qpow(bar A,ll b){
    bar ret=e;
    while(b){
        if(b&1)ret=ret*A;
        A=A*A;
        b>>=1;
    }return ret;
}
int main(){
    e.ch[0][0]=e.ch[1][1]=1;
    scanf("%lld %lld",&n,&m);
    n=gcd(n,m);
    bar f,o;
    f.ch[0][0]=0;f.ch[0][1]=f.ch[1][0]=f.ch[1][1]=1;
    bar N=qpow(f,n-1);x=(N.ch[0][0]+N.ch[1][0])%mod;
    printf("%lld",x);
    return 0;
}
