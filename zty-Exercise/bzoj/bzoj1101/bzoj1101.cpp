#include<bits/stdc++.h>
using namespace std;
const int N = 50010;
int v[N],n,a,b,d,mu[N];
void get_mu(){
    for(int i=1;i<N;i++)mu[i]=1,v[i]=0;
    for(int i=2;i<N;i++){
        if(v[i])continue;
        mu[i]=-1;
        for(int j=2*i;j<N;j+=i){
            v[j]=1;
            if((j/i)%i==0)mu[j]=0;
            else mu[j]*=-1;
        }
    }
    for(int i=1;i<N;i++)
        mu[i]+=mu[i-1];
}
void read(int & x){
    x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
}
int main(){
    get_mu();
    read(n);
    while(n--){
        long long ans=0;
        read(a);read(b);read(d);
        int mm=min(a/d,b/d);
        for(int l=1,r;l<=mm;l=r+1){
            int A=a/d,B=b/d;
            r=min(A/(A/l),B/(B/l));
            ans+=1ll*(mu[r]-mu[l-1])*(A/l)*(B/l);
        }
        printf("%lld\n",ans);
    }
    return 0;
}