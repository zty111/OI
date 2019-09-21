// hdu5391 Zball in Tina Town
//[数学]
//威尔逊定理 朴素判断素数
//zty111
#include<cstdio>
using namespace std;
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return false;
    return true;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(is_prime(n))printf("%d\n",n-1);
        else if(n==4)printf("2\n");
        else printf("0\n");
    }
    return 0;
}