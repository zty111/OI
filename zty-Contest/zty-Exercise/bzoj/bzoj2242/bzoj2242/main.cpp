#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
int qpow(int a,int b,int p){
    a%=p;b%=(p-1);
    int ret=1;
    while(b){
        if(b&1)ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }return ret;
}
int bgsg(int a,int b,int p){
    map<int,int>ha;ha.clear();
    b%=p;
    int t=(int)sqrt(p)+1;
    for(int j=0;j<t;j++){
        int val=1ll*b*qpow(a,j,p)%p;
        ha[val]=j;
    }
    a=qpow(a,t,p);
    if(a==0)return b==0?1:-1;
    for(int i=0;i<=t;i++){
        int val=qpow(a,i,p);
        int j=ha.find(val)==ha.end()?-1:ha[val];
        if(j>=0&&i*t-j>=0)return i*t-j;
    }
    return -1;
}
int main(){
    int t,k,a,b,p;
    scanf("%d %d",&t,&k);
    while(t--){
        scanf("%d %d %d",&a,&b,&p);
        if(k==1)printf("%d\n",qpow(a,b,p));
        if(k==2){
            if(a%p==0)printf("Orz, I cannot find x!\n");
            else printf("%d\n",(1ll*b*qpow(a,p-2,p)%p+p)%p);
        }
        if(k==3){
            int ans=bgsg(a,b,p);
            if(ans==-1)printf("Orz, I cannot find x!\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
