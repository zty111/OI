#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=400010;

ll sum[N];
ll tag[N];

namespace Segment
{
	#define ls rt<<1
	#define rs rt<<1|1
	
	void maintain(int rt)
	{
		sum[rt]=sum[ls]+sum[rs];
	}
	
	void pushdown(int rt,int k)
	{
		if(!tag[rt]) return;
		tag[ls]+=tag[rt];
		tag[rs]+=tag[rt];
		sum[ls]+=tag[rt]*(k-(k>>1));
		sum[rs]+=tag[rt]*(k>>1);
		tag[rt]=0;
	}
	
	void update(int rt,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l)
		if(qr>=r)
		{
			tag[rt]+=k;
			sum[rt]+=1LL*k*(r-l+1);
			return;
		}
		pushdown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(ql<=mid) update(ls,l,mid,ql,qr,k);
		if(qr>mid) update(rs,mid+1,r,ql,qr,k);
		maintain(rt);
	}
	
	void build(int rt,int l,int r)
	{
		tag[rt]=0;
		if(l==r)
		{
			scanf("%d",&sum[rt]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		maintain(rt);
	}
	
	ll query(int rt,int l,int r,int ql,int qr)
	{
		if(ql<=l)
		if(qr>=r) return sum[rt];
		pushdown(rt,r-l+1);
		int mid=(l+r)>>1;
		ll ret=0;
		if(ql<=mid) ret+=query(ls,l,mid,ql,qr);
		if(qr>mid) ret+=query(rs,mid+1,r,ql,qr);
		return ret;
	}
}
using namespace Segment;

int n,q;
int opt;
int t1;
int t2;
int t3;

int main()
{
	scanf("%d",&n);
	scanf("%d",&q);
	build(1,1,n);
	while(q--)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			scanf("%d",&t3);
			update(1,1,n,t1,t2,t3);
		}
		if(opt==2)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			ll ans=query(1,1,n,t1,t2);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
