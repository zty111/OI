#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int INF=0x7f7f7f7f;

int n;
int cnt;
int root;

struct node
{
	int s[2];
}T[N];

int siz[N];
int val[N];
int rnd[N];

#define ls s[0]
#define rs s[1]

void maintain(int rt)
{
	int ll=T[rt].ls;
	int rr=T[rt].rs;
	siz[rt]=siz[ll]+siz[rr]+1;
}

int insert(int w)
{
	cnt++;
	siz[cnt]=1;
	val[cnt]=w;
	rnd[cnt]=rand();
	return cnt;
}

int merge(int x,int y)
{
	if(!x) return x+y;
	if(!y) return x+y;
	if(rnd[x]<rnd[y])
	{
		T[x].rs=merge(T[x].rs,y);
		maintain(x);
		return x;
	}
	else
	{
		T[y].ls=merge(x,T[y].ls);
		maintain(y);
		return y;
	}
}

void split(int rt,int k,int &x,int &y)
{
	if(rt)
	{
		if(val[rt]<=k)
		{
			x=rt;
			split(T[rt].rs,k,T[rt].rs,y);
		}
		else
		{
			y=rt;
			split(T[rt].ls,k,x,T[rt].ls);
		}
		maintain(rt);
	}
	else x=y=0;
}

int kth(int rt,int k)
{
	while(true)
	{
		int ll=T[rt].ls;
		int rr=T[rt].rs;
		if(k<=siz[ll]) rt=ll;
		else if(k==siz[ll]+1) return rt;
		else 
		{
			k-=(siz[ll]+1);
			rt=rr;
		}
	}
}

int opt;
int tmp;
int x,y,z;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&opt);
		scanf("%d",&tmp);
		if(opt==1)
		{
			split(root,tmp,x,y);
			root=merge(merge(x,insert(tmp)),y);
		}
		if(opt==2)
		{
			split(root,tmp,x,z);
			split(x,tmp-1,x,y);
			y=merge(T[y].ls,T[y].rs);
			root=merge(merge(x,y),z);
		}
		if(opt==3)
		{
			split(root,tmp-1,x,y);
			printf("%d\n",siz[x]+1);
			root=merge(x,y);
		}
		if(opt==4)
		{
			tmp=kth(root,tmp);
			printf("%d\n",val[tmp]);
		}
		if(opt==5)
		{
			split(root,tmp-1,x,y);
			tmp=kth(x,siz[x]);
			printf("%d\n",val[tmp]);
			root=merge(x,y);
		}
		if(opt==6)
		{
			split(root,tmp,x,y);
			tmp=kth(y,1);
			printf("%d\n",val[tmp]);
			root=merge(x,y);
		}
	}
	return 0;
}
