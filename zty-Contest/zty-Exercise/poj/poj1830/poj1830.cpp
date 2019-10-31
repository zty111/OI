#include<cstdio>
#include<iostream>
using namespace std;
int a[100],n,t,ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1,j;i<=n;i++){
            scanf("%d",&j);
            a[i]^=j;
            a[i]|=1<<i;//a[i][i]=1;zip
        }
        int x,y;
        while(~scanf("%d%d",&x,&y)&&x&&y){
            a[y]|=1<<x;//a[y][x]=1;
        }
        ans=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                if(a[j]>a[i])swap(a[i],a[j]);
            if(a[i]==0){ans=1<<(n-i+1);break;}
            if(a[i]==1){ans=0;break;}
            for(int k=n;k;k--)
                if(a[i]>>k&1){
                    for(int j=1;j<=n;j++)
                        if(i!=j&&(a[j]>>k&1))a[j]^=a[i];
                    break;
                }
        }
        if(ans==0)puts("Oh,it's impossible~!!");
        else printf("%d\n",ans);
    }
    return 0;
}