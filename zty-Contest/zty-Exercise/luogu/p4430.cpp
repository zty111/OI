#include<bits/stdc++.h>
using namespace std;
const int p = 9999991;
int main(){
    long long n,ans=1;
    scanf("%lld",&n);
    for(int i=1;i<=n-2;i++)ans=ans*n%p;
    for(int i=1;i<=n-1;i++)ans=ans*i%p;
    printf("%lld\n",ans);
    return 0;
}