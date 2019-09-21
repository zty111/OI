#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;

const int N=500010;

int n,m;
int a[N];
int tmp;
int opt;
int t1;
int t2;
int tw;
int t;


void change(int rt,int k)
{
	while(rt<=n)
	{
		a[rt]+=k;
		rt+=lowbit(rt);
	}
}

int query(int rt)
{
	int ans=0;
	while(rt)
	{
		ans+=a[rt];
		rt-=lowbit(rt);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1,tmp=0;i<=n;i++)
	{
		scanf("%d",&t);
		change(i,t-tmp);
		tmp=t;
	}
	while(m--)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			scanf("%d",&tw);
			change(t1,tw);
			change(t2+1,-tw);
		}
		if(opt==2)
		{
			scanf("%d",&t1);
			int ans=query(t1);
			printf("%d\n",ans);
		}
	}
	return 0;
}

