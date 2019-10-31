// p4549 裴蜀定理
//[数学]
//裴蜀定理 gcd
//zty111
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int ans,n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        a=a>0?a:-a;
        if(i==1)ans=a;
        else ans=gcd(ans,a);
    }
    printf("%d\n",ans);
    return 0;
}