#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
long long lcm(int a,int b){
    return 1ll*a*b/gcd(a,b);
}
int main(){
    int n,ans,a0,a1,b0,b1;
    scanf("%d",&n);
    while(n--){
        ans=0;
        scanf("%d %d %d %d",&a0,&a1,&b0,&b1);
        for(int i=1;i<=sqrt(b1);i++){
            if(b1%i==0){
                if(gcd(i,a0)==a1&&lcm(i,b0)==b1)
                    ans++;
                if(i*i!=b1&&gcd(b1/i,a0)==a1&&lcm(b1/i,b0)==b1)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}