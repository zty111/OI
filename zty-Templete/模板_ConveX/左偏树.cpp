#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int val[N];
int dep[N];
int fa[N];
int ls[N];
int rs[N];

int find(int x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

int merge(int x,int y)
{
	if(x==0) return x+y;
	if(y==0) return x+y;
	if(val[x]>val[y]) swap(x,y);
	if(val[x]==val[y])
	if(x>y) swap(x,y);
	rs[x]=merge(rs[x],y);
	fa[rs[x]]=x;
	if(dep[ls[x]]<dep[rs[x]])
	swap(ls[x],rs[x]);
	dep[x]=dep[rs[x]]+1;
	return x;
}

void pop(int x)
{
	val[x]=-1;
	fa[ls[x]]=ls[x];
	fa[rs[x]]=rs[x];
	fa[x]=merge(ls[x],rs[x]);
}

int m,n;
int opt;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	dep[0]=-1;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d",&val[i]);
	}
	while(m--)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			if(!(~val[t1])) continue;
			if(!(~val[t2])) continue;
			if(t1==t2) continue;
			int p1=find(t1);
			int p2=find(t2);
			merge(p1,p2);
		}
		if(opt==2)
		{
			scanf("%d",&t1);
			if(!(~val[t1])) puts("-1");
			else
			{
				int p1=find(t1);
				printf("%d\n",val[p1]);
				pop(p1);
			}
		}
	}
	return 0;
}
