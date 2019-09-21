#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int M=25000010;
const int INF=0x7fffffff;

int root;
int cnt;
int m,n;

int rt[N];
int siz[M];
int val[M];
int lch[M];
int rch[M];
int rnd[M];

void maintain(int rt)
{
	int ll=lch[rt];
	int rr=rch[rt];
	siz[rt]=siz[ll]+siz[rr]+1;
}

int insert(int x)
{
	cnt++;
	siz[cnt]=1;
	val[cnt]=x;
	rnd[cnt]=rand();
	return cnt;
}

void copy(int x,int y)
{
	lch[x]=lch[y];
	rch[x]=rch[y];
	rnd[x]=rnd[y];
	siz[x]=siz[y];
	val[x]=val[y];
	return;
}

int merge(int x,int y)
{
	if(x==0) return x+y;
	if(y==0) return x+y;
	if(rnd[x]<rnd[y])
	{
		int p=++cnt;
		copy(p,x);
		rch[p]=merge(rch[p],y);
		maintain(p);
		return p;
	}
	else 
	{
		int p=++cnt;
		copy(p,y);
		lch[p]=merge(x,lch[p]);
		maintain(p);
		return p;
	}
}

void split(int rt,int k,int &x,int &y)
{
	if(rt)
	{
		if(val[rt]<=k)
		{
			x=++cnt;
			copy(x,rt);
			split(rch[x],k,rch[x],y);
			maintain(x);
		}
		else
		{
			y=++cnt;
			copy(y,rt);
			split(lch[y],k,x,lch[y]);
			maintain(y);
		}
	}
	else x=y=0;
}

void del(int &rt,int w)
{
	int x=0;
	int y=0;
	int z=0;
	split(rt,w,x,z);
	split(x,w-1,x,y);
	y=merge(lch[y],rch[y]);
	rt=merge(merge(x,y),z);
}

void ins(int &rt,int w)
{
	int x=0;
	int y=0;
	int z=0;
	split(rt,w,x,y);
	z=insert(w);
	rt=merge(merge(x,z),y);
}

int rnk(int k,int w)
{
	if(w==siz[lch[k]]+1) return val[k];
	if(w<=siz[lch[k]]) return rnk(lch[k],w);
	return rnk(rch[k],w-siz[lch[k]]-1);
}

int kth(int &rt,int w)
{
	int x=0;
	int y=0;
	split(rt,w-1,x,y);
	int ans=siz[x]+1;
	return ans;
}

int pre(int &rt,int w)
{
	int x=0;
	int y=0;
	int z=0;
	split(rt,w-1,x,y);
	if(x==0) return -INF;
	z=siz[x];
	int ans=rnk(x,z);
	rt=merge(x,y);
	return ans;
}

int nxt(int &rt,int w)
{
	int x=0;
	int y=0;
	split(rt,w,x,y);
	if(y==0) return INF;
	int ans=rnk(y,1);
	rt=merge(x,y);
	return ans;
}

int op;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t1);
		scanf("%d",&op);
		scanf("%d",&t2);
		rt[i]=rt[t1];
		if(op==1) ins(rt[i],t2);
		if(op==2) del(rt[i],t2);
		if(op==3) printf("%d\n",kth(rt[i],t2));
		if(op==4) printf("%d\n",rnk(rt[i],t2));
		if(op==5) printf("%d\n",pre(rt[i],t2));
		if(op==6) printf("%d\n",nxt(rt[i],t2));
	}
	return 0;
}
