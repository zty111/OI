// p4593 教科书般的亵渎
//[数学]
//拉格朗日插值 1-n
//zty111
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1e9+7;
const int N = 60;
int ans,num,pro,a[N],f[N],fac[N]={1};
inline void read(int & x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
}
inline int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }return ret;
}
int Lagrange(int n,int k){
    pro=1,num=0;
    if(n<=k)return f[n];
    for(int i=1;i<=k;i++)
        pro=pro*(n-i)%p;
    for(int i=1;i<=k;i++){
        int inv1=qpow(n-i,p-2);
        int inv2=qpow((fac[i-1]%p*fac[k-i])%p,p-2);
        int sign=(k-i)&1?-1:1;
        num=(num+sign*inv1*inv2%p*f[i]%p*pro%p)%p;
    }return (num+p)%p;
}
signed main(){
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%p;
    int T,n,m;
    read(T);
    while(T--){
        read(n);read(m);
        for(int i=1;i<=m+3;i++)
            f[i]=(f[i-1]+qpow(i,m+1))%p;
        for(int i=1;i<=m;i++)
            read(a[i]);
        sort(a+1,a+m+1);ans=0;
        for(int i=0;i<=m;i++){
            ans=(ans+Lagrange(n-a[i],m+3))%p;
            for(int j=i+1;j<=m;j++)ans=(ans+p-qpow(a[j]-a[i],m+1))%p;
        }printf("%lld\n",(ans+p)%p);
    }
    return 0;
}