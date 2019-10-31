// p2257 yy的gcd
//[数学]
//莫比乌斯反演
//zty111
#include<bits/stdc++.h>
using namespace std;
const int N = 10000010;
void read(int & x){
    x=0;;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
}
int mu[N],prim[N],cnt;bool vis[N];
long long sum[N],g[N];
void get_mu(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){prim[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&prim[j]*i<=n;j++){
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
            else mu[prim[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j*prim[i]<=n;j++){
            g[prim[i]*j]+=mu[j];
        }
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+g[i];
}
int main(){
    get_mu(N-10);
    int T,N,M;
    read(T);
    while(T--){
        long long ans=0;
        read(N);read(M);
        int n=min(N,M);
        for(int l=1,r;l<=n;l=r+1){
            r=min(N/(N/l),M/(M/l));
            ans+=1ll*(N/l)*(M/l)*(sum[r]-sum[l-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}