#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
ll a[maxn],b[maxn];
ll i,j,k,l,t,n,m,ans,T,p,fr,ans1;
int main(){
    for(scanf("%lld",&T);T;T--){
        scanf("%lld%lld",&n,&m);
        fo(i,1,n)scanf("%lld",&a[i]);ans=0;
        fo(p,1,m/n){
            fo(i,1,n)b[i]=a[i];
            fod(i,n,2)a[i-1]=min(a[i-1],a[i]-p);
            if(p*(p-1)/2*n+p>a[1])break;
            ans1=(1+n*p)*(n*p)/2;fr=m-n*p;
            t=a[1]-p*(p-1)/2*n-p;
            if(fr<t){
                l=t/fr;
                if(l>=p){l=p-1;ans1+=(l+1)*fr*n;k=(l+1)*fr;fr=0;}
                else {ans1+=t%fr*n+l*fr*n,k=t%fr+l*fr;if(l==p-1)fr-=t%fr;}
            }
            else ans1+=t*n,k=t,fr-=(p==1)*t;
            fo(i,2,n){
                t=a[i]-p*(p-1)/2*n-p*i-k;
                ans1+=min(fr,t)*(n-i+1);k+=min(fr,t);
                fr-=min(fr,t);
                if(!fr)break;
            }
            ans=max(ans,ans1);
            fo(i,1,n)a[i]=b[i];
        }
        printf("%lld\n",ans);
    }
}