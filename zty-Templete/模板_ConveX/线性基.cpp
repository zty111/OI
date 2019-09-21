#include<bits/stdc++.h>
using namespace std;

const int N=70;
const int P=60;

long long a[N];
long long ans;
long long tmp;
int n;

int main()
{
    scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&tmp);
		for(int x=P;~x;x--)
		{
			if(tmp&(1LL<<x))
			{
				if(!a[x])
				{
					a[x]=tmp;
					break;
				}
				else tmp^=a[x];
			}
		}
	} 
	for(int x=P;~x;x--)
	{
		if((ans^a[x])<=ans) continue;
		ans=ans^a[x];
	}
	printf("%lld\n",ans);
	return 0;
}
