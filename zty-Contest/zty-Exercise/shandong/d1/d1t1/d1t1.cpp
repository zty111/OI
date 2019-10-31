#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100010],ans,p;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0;p=n;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)
            if(p==a[i])p--,ans++;
        printf("%d\n",n-ans);
    }
    return 0;
}