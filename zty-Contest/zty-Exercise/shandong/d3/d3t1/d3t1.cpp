#include<bits/stdc++.h>
using namespace std;
int n,m,d,h,dl,hl,ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&d,&h);
        int a=d-dl+abs(h-hl)+1;
        if(a<0){ans=-1;break;}
        ans=max(ans,(max(h,hl)+a>>1));
        dl=d;hl=h;
    }
    if(ans=-1)printf("IMPOSSIBLE\n");
    else printf("%d\n",ans);
    return 0;
}