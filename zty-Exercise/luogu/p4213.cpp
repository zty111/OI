#include<bits/stdc++.h>
using namespace std;
void read(int & x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
}
typedef long long ll;
const int maxn = 10000000;
ll sumu[maxn],Smu[maxn],sump[maxn],Sphi[maxn];
inline void shai(){
    
}
ll GetSumu(int n){
    if(n<=N)return sumu[n];
    if(Smu[n])return Smu[n];
    ll ret=1ll;
    for(int l=2,r;l<=n;l=r+1){
        r=n/(n/l);ret-=(r-l+1)*GetSumu(n/l);
    }return Smu[n]=ret;
}
inline ll GetSphi(int n){
    if(n<=N)return sump[n];
    if(Sphi[n])return Sphi[n];
    ll ret=1ll*n*(n+1)/2;
    for(int l=2,r;l<=n;l=r+1){
        r=n/(n/l);ret-=(r-l+1)*GetSphi(n/l);
    }return Sphi[n]=ret;
}
int main(){
    int T,N;
    ll ans1,ans2;
    read(T);
    while(T--){
        read(N);
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}