#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
long long sum;
long long chushu;
long long a[100050];
int n;
long long ans;
bool cmp(long long a,long long b)
{
	return a>b;
}
long long sumx[105605];
long long need;
int mark;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	chushu=sum;
	for(long long i=2;i<=sqrt(sum);i++)
	{
		if(sum%i==0)
		{
			chushu=i;
			break;
		}
	}
    printf("%lld\n",sum);
    printf("%lld\n",chushu);
	for(int i=1;i<=n;i++)
	{
		a[i]%=chushu;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sumx[i]=sumx[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(need==sumx[n]-sumx[i-1])
		{
			printf("%lld",need);
			exit(0);
		}
		else
		{
			need+=chushu-a[i];			
		}
	}
	return 0;
}
