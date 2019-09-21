#include<bits/stdc++.h>
using namespace std;
int n;double p,ans,x,x2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&p);
        ans+=(3.0*x2+3.0*x+1.0)*p;
        x2=(x2+2*x+1.0)*p;
        x=(x+1)*p;
    }
    printf("%.1lf\n",ans);
    return 0;
}