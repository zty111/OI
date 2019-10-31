#include<bits/stdc++.h>
using namespace std;
int s[80010],top,n,a;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        while(top&&s[top]<=a)top--;
        ans+=top;
        s[++top]=a;
    }
    printf("%lld\n",ans);
    return 0;
}