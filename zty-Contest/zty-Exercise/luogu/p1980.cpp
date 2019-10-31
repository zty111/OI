#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        int k=i;
        while(k>0){
            if(k%10==x)ans++;
            k/=10;
        }
    }
    printf("%d",ans);
    return 0;
}
