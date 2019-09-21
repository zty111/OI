#include<bits/stdc++.h>
using namespace std;
int T,n,t,a,b,c,f[3500],ans;
struct game{
    int a,b,c;
}A[1010];
bool cmp(game A,game B){
    return 1.0*A.b/A.c > 1.0*B.b/B.c;
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f));ans=0;
        scanf("%d%d",&n,&t);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
        sort(A+1,A+1+n,cmp);
        for(int i=1;i<=n;i++)
            for(int j=t;j>=0;j--)
                if(j>=A[i].c)f[j]=max(f[j],f[j-A[i].c]+A[i].a-A[i].b*j);
        for(int i=0;i<=t;i++)ans=max(ans,f[i]);
        printf("%d\n",ans);
    }
    return 0;
}