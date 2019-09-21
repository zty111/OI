#include<bits/stdc++.h>
using namespace std;
const int p=10007;
long long a,b,k,n,m;
long long c[1010][1010];
long long qpow(long long a,long long b){
    long long ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }return ret;
}
int main(){
    scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
    for(int i=0;i<=k;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
    }
    long long ans=qpow(b,m)*qpow(a,k-m)%p*c[k][m]%p;
    printf("%lld\n",ans);
    return 0;
}
