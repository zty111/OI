#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int M=25000010;

int root[N];
int val[M];
int ls[M];
int rs[M];
int a[N];
int b[N];
int tot;

void build(int &rt,int l,int r)
{
	rt=++tot;
	if(l==r)
	{
		val[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls[rt],l,mid);
	build(rs[rt],mid+1,r);
}

void insert(int &rt,int v,int l,int r,int q,int k)
{
	rt=++tot;
	ls[rt]=ls[v];
	rs[rt]=rs[v];
	val[rt]=val[v];
	if(l==r)
	{
		val[rt]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid) insert(ls[rt],ls[v],l,mid,q,k);
	else insert(rs[rt],rs[v],mid+1,r,q,k);
}

int query(int rt,int l,int r,int q)
{
	if(l==r) return val[rt];
	int mid=(l+r)>>1;
	if(q<=mid) return query(ls[rt],l,mid,q);
	else return query(rs[rt],mid+1,r,q);
}

int m,n;
int siz;
int opt;
int t1;
int t2;
int t3;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t1);
		scanf("%d",&opt);
		scanf("%d",&t2);
		if(opt==1)
		{
			scanf("%d",&t3);
			insert(root[i],root[t1],1,n,t2,t3);
		}
		if(opt==2)
		{
			int ans=query(root[t1],1,n,t2);
			printf("%d\n",ans); 
			root[i]=root[t1];
		}
	}
	return 0;
}
