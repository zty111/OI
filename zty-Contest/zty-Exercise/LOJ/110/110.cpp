#include<cstdio>
using namespace std;
const int p = 1e9+7;
const int mod = 998244353;
int n,a;
long long ans;
int qpow(int a,int b,int p){
    int res = 1;
    while(b){
        if(b&1)res=1ll*res*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }return res;
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int x=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
    return x;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a=read();
        ans=(ans+1ll*qpow(a,p-2,p)*qpow(mod,n-i,p)%p)%p;
    }
    printf("%lld\n",ans);
    return 0;
}