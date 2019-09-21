//uva10140
//[数学]
//素数筛法
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 1e6+10;
int vis[N],val[N],prim[N],cnt,p[N],c;
void shai(int n){
    for(int i=2;i<N;i++){
        if(!vis[i])prim[++cnt]=i;
        for(int j=1;j<=cnt&&i*prim[j]<N;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
        }
    }
}
signed main(){
    int l,r,maxx,minn,ans1,ans2,ans3,ans4;
    shai(N);
    while(scanf("%d%d",&l,&r)==2){
        c=0;maxx=-1;minn=1e7;
        memset(val,0,sizeof(val));
        if(l==1)val[0]=1;
        for(int i=1;i<=cnt;i++)
            for(long long j=l/prim[i];j*prim[i]<=r;j++){
                long long x=prim[i]*j;
                if(j>1&&x>=l)val[x-l]=1;
            }
        for(long long i=l;i<=r;i++)
            if(!val[i-l])p[++c]=i;
        for(int i=1;i<c;i++){
            if(p[i+1]-p[i]>maxx)maxx=p[i+1]-p[i],ans1=p[i],ans2=p[i+1];
            if(p[i+1]-p[i]<minn)minn=p[i+1]-p[i],ans3=p[i],ans4=p[i+1];
        }
        if(maxx!=-1)printf("%d,%d are closest, %d,%d are most distant.\n",ans3,ans4,ans1,ans2);
        else printf("There are no adjacent primes.\n");
    }
    return 0;
}