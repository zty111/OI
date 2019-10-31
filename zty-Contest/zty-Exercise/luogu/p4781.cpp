// p4781 拉格朗日插值
//[数学]
//拉格朗日插值
//zty111
#include<bits/stdc++.h>
using namespace std;
inline void read(int & x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();
}
const int p = 998244353;
int x[2010],y[2010];
inline int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }return ret;
}
inline int inv(int n){return qpow(n%p,p-2);}
int main(){
    int n,k;
    read(n);read(k);
    for(int i=1;i<=n;i++){
        read(x[i]);read(y[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=1;
        for(int j=1;j<=n;j++)
            if(j!=i)cnt=(1ll*cnt*(k-x[j])%p*inv(x[i]-x[j]))%p;
        ans=(ans+1ll*cnt*y[i]%p)%p;
    }
    printf("%d\n",(ans+p)%p);
    return 0;
}