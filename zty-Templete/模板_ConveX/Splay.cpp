#include<bits/stdc++.h>
using namespace std;

const int N=200010;

#define ls s[0]
#define rs s[1]

struct node
{
	int s[2];
	int fa;
}T[N];

int val[N];
int tag[N];
int siz[N];

void maintain(int rt)
{
	int ll=T[rt].ls;
	int rr=T[rt].rs;
	siz[rt]=siz[ll]+siz[rr]+1;
}

void pushdown(int rt)
{
	int ll=T[rt].ls;
	int rr=T[rt].rs;
	if(tag[rt])
	{
		tag[ll]^=1;
		tag[rr]^=1;
		tag[rt]^=1;
		swap(T[rt].ls,T[rt].rs);
	}
}

int root;

void rotate(int x)
{
	int y=T[x].fa;
	int z=T[y].fa;
	bool jud1=(T[y].rs==x);
	bool jud2=(T[z].rs==y);
	T[z].s[jud2]=x;
	T[x].fa=z;
	T[y].s[jud1]=T[x].s[jud1^1];
	T[T[x].s[jud1^1]].fa=y;
	T[x].s[jud1^1]=y;
	T[y].fa=x;
	maintain(y);
	maintain(x);
}

void splay(int x,int goal)
{
	while(T[x].fa!=goal)
	{
		int y=T[x].fa;
		int z=T[y].fa;
		if(z!=goal)
		{
			bool jud1=(T[z].rs==y);
			bool jud2=(T[y].rs==x);
			if(jud1^jud2) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	if(!goal) root=x;
}

int kth(int x)
{
	int cur=root;
	while(true)
	{
		pushdown(cur);
		int ll=T[cur].ls;
		if(siz[ll]>=x) cur=T[cur].ls;
		else if(siz[ll]==x-1) return cur;
		else
		{
			x-=(siz[ll]+1);
			cur=T[cur].rs;
		}
	}
}

int m,n;

void write(int x)
{
	pushdown(x);
	if(T[x].ls) write(T[x].ls);
	if(val[x]>1)
	if(val[x]<n+2) printf("%d ",val[x]-1);
	if(T[x].rs) write(T[x].rs);
}

int cnt;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n+2;i++)
	{
		int x=root;
		int f=0;
		while(x)
		{
			f=x;
			bool jud1=(i>val[x]);
			x=T[x].s[jud1];
		}
		x=++cnt;
		if(f)
		{
			bool jud2=(i>val[f]);
			T[f].s[jud2]=x;
		}
		T[x].ls=0;
		T[x].rs=0;
		T[x].fa=f;
		val[x]=i;
		siz[x]=1;
		splay(x,0);
	}
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		int ll=kth(t1);
		int rr=kth(t2+2);
		splay(ll,0);
		splay(rr,ll);
		tag[T[T[root].rs].ls]^=1;
	}
	write(root);
	puts("");
	return 0;
}
