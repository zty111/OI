#include<bits/stdc++.h>
using namespace std;

const int N=200010;
const int M=5000010;

int root[N];
int sum[M];
int ls[M];
int rs[M];
int a[N];
int b[N];
int tot;

void build(int &rt,int l,int r)
{
	rt=++tot;
	sum[rt]=0;
	if(l<r)
	{
		int mid=(l+r)>>1;
		build(ls[rt],l,mid);
		build(rs[rt],mid+1,r);
	}
}

void update(int &rt,int v,int l,int r,int q)
{
	rt=++tot;
	ls[rt]=ls[v];
	rs[rt]=rs[v];
	sum[rt]=sum[v]+1;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(q<=mid) update(ls[rt],ls[v],l,mid,q);
		else update(rs[rt],rs[v],mid+1,r,q);
	}
}

int query(int u,int v,int l,int r,int q)
{
	if(l>=r) return l;
	int x=sum[ls[v]]-sum[ls[u]];
	int mid=(l+r)>>1;
	if(q<=x) return query(ls[u],ls[v],l,mid,q);
	else return query(rs[u],rs[v],mid+1,r,q-x);
}

int t1;
int t2;
int t3;
int tmp;
int m,n,q; 

int main()
{
	scanf("%d",&n);
	scanf("%d",&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	build(root[0],1,m);
	for(int i=1;i<=n;i++)
	{
		tmp=lower_bound(b+1,b+m+1,a[i])-b;
		update(root[i],root[i-1],1,m,tmp);
	}
	while(q--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		scanf("%d",&t3);
		int ans=query(root[t1-1],root[t2],1,m,t3);
		printf("%d\n",b[ans]);
	}
	return 0;
}
