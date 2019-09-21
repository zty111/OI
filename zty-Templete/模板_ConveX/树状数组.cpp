#include<bits/stdc++.h>
#define lowbit(i) i&(-i)
using namespace std; 

const int N=500010;

int m;
int n;

namespace BIT
{
	int a[N];
	void add(int x,int k)
	{
		while(x<=n)
		{
			a[x]+=k;
			x+=lowbit(x);
		}
	}
	
	int query(int x)
	{
		int ans=0;
		while(x)
		{
			ans+=a[x];
			x-=lowbit(x);
		}
		return ans;
	}
}
using namespace BIT;

int tmp;
int opt;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		add(i,tmp);
	}
	while(m--)
	{
		scanf("%d",&opt);
		scanf("%d",&t1);
		scanf("%d",&t2);
		if(opt==1)  add(t1,t2);
		if(opt==2)
		{
			int ans=0;
			ans=ans+query(t2);
			ans=ans-query(t1-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
