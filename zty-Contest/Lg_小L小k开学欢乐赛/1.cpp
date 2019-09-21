#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
const int p = 998244353;
int x[100010],y[100010];
inline int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }return ret;
}
const int N = 50000000;
int inv[N];
inline int invv(int nn){
    nn%=p;
    if(nn<N&&inv[nn])return inv[nn];
    else return qpow(nn,p-2);
}
int main(){
    inv[1]=1;
    for(int i=2;i<N;i++)
        inv[i]=1ll*(p-p/i)*inv[p%i]%p;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        if(n>=p){
            printf("-1\n");
            continue;
        }
        int ans=0,k=n+1;
        for(int i=1;i<=n;i++){
            x[i]=i;
            y[i]=inv[i];
        }
        for(int i=1;i<=n;i++){
            int cnt=1;
            for(int j=1;j<=n;j++)
                if(j!=i)cnt=(1ll*cnt*(k-x[j])%p*invv(x[i]-x[j]))%p;
            ans=(ans+1ll*cnt*y[i]%p)%p;
        }
        printf("%d\n",(ans+p)%p);
    }
    return 0;
}