// p3811 乘法逆元
//[数学]
//线性逆元
//zty111
#include<bits/stdc++.h>
using namespace std;
const int N = 3000010;
int inv[N];
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    inv[1]=1;printf("1\n");
    for(int i=2;i<=n;i++)
        printf("%d\n",inv[i]=1ll*(p-p/i)*inv[p%i]%p);
    return 0;
}