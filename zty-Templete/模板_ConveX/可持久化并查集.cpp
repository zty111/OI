#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=3000010;

int root[M];
int val[M];
int lch[M];
int rch[M];
int fa[M];
int tot;
int m,n;



void build(int &rt,int l,int r)
{
	rt=++tot;
	if(l==r)
	{
		fa[rt]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(lch[rt],l,mid);
	build(rch[rt],mid+1,r);
}

void update(int &rt,int v,int l,int r,int f,int k)
{
	rt=++tot;
	lch[rt]=lch[v];
	rch[rt]=rch[v];
	if(l==r)
	{
		fa[rt]=f;
		val[rt]=val[v];
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)  update(lch[rt],lch[v],l,mid,f,k);
	if(k>mid) update(rch[rt],rch[v],mid+1,r,f,k);
}

int query(int rt,int l,int r,int k)
{
	if(l==r) return rt;
	int mid=(l+r)>>1;
	if(k<=mid) return query(lch[rt],l,mid,k);
	else return query(rch[rt],mid+1,r,k);
}

int find(int rt,int x)
{
	int k=query(rt,1,n,x);
	if(x==fa[k]) return k;
	return find(rt,fa[k]);
}

void maintain(int rt,int l,int r,int k)
{
	if(l==r)
	{
		val[rt]++;
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)  maintain(lch[rt],l,mid,k);
	if(k>mid) maintain(rch[rt],mid+1,r,k);
}

void unite(int t1,int t2,int R)
{
	int p1=find(root[R],t1);
	int p2=find(root[R],t2);
	if(fa[p1]==fa[p2]) return;
	if(val[p1]>val[p2]) swap(p1,p2);
	update(root[R],root[R-1],1,n,fa[p2],fa[p1]);
	if(val[p1]==val[p2])
	maintain(root[R],1,n,fa[p2]);
}

bool check(int t1,int t2,int R)
{
	int p1=find(root[R],t1);
	int p2=find(root[R],t2);
	return fa[p1]==fa[p2];
}

int opt;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			root[i]=root[i-1];
			unite(t1,t2,i);
		}
		if(opt==2)
		{
			scanf("%d",&t1);
			root[i]=root[t1];
		}
		if(opt==3)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			root[i]=root[i-1];
			bool ans=check(t1,t2,i);
			if(ans) puts("1");
			else puts("0");
		}
	}
	return 0;
}
