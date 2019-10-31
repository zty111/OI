#include<bits/stdc++.h>
using namespace std;
int x,n,tim,ans;
int main(){
    scanf("%d%d",&x,&n);
    ans+=250*5*(n/7);
    n%=7;
    for(int i=1;i<=n;i++){
        if(x%7!=6&&x%7!=0)ans+=250;
        x++;
    }
    printf("%d\n",ans);
    return 0;
}
