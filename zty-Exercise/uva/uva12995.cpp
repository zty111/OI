// UVA12995 Farey Sequence
//[数学]
//欧拉筛 欧拉函数
//zty111

#include<cstdio>
using namespace std;
const int N = 1000001;
int phi[N];
long long ans[N];
void phi_table(int n)
{
    for(int i=2;i<=n;i++)phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++)if(!phi[i])
    for(int j=i;j<=n;j+=i)
    {
        if(!phi[j])phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
    }
}
int main()
{
    int n;
    phi_table(N);
    for(int i=2;i<=N;i++)
    ans[i]=ans[i-1]+phi[i];
    while(scanf("%d",&n)==1&&n)
        printf("%lld\n",ans[n]);
    return 0;
}