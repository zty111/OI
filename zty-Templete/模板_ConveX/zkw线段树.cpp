#include<bits/stdc++.h>
using namespace std;

const int N=1<<19;
const int INF=0x3f3f3f3f;

int T[N<<1];
int m,n;
int opt;
int tmp;
int t1;
int t2;

namespace zkw_Seg
{
	#define ls rt<<1
	#define rs rt<<1|1
	
	int query(int l,int r)
	{
		l+=(N-1);
		r+=(N+1);
		int ans=0;
		while(l^r^1)
		{
			if(~l&1) ans+=T[l^1];
			if( r&1) ans+=T[r^1];
			l>>=1;
			r>>=1;
		}
		return ans;
	}
	
	void add(int rt,int k)
	{
		rt+=N;
		T[rt]+=k;
		rt>>=1;
		while(rt)
		{
			T[rt]=T[rs]+T[ls];
			rt>>=1;
		}
	}
}
using namespace zkw_Seg;

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
		if(opt==1) add(t1,t2);
		if(opt==2)
		{
			int ans=query(t1,t2);
			printf("%d\n",ans);
		}
	}
	return 0;
}
