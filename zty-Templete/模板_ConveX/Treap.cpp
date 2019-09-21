#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int INF=0x3f3f3f3f;

int siz[N];
int cnt[N];
int val[N];
int rnd[N];
int lch[N];
int rch[N];
int size;
int rt,n;
int ans;
int opt;
int tmp;

void maintain(int rt)
{
	int ll=lch[rt];
	int rr=rch[rt];
	siz[rt]=siz[ll]+siz[rr]+cnt[rt];
}

void LR(int &x)
{
	int y=rch[x];
	rch[x]=lch[y];
	lch[y]=x;
	siz[y]=siz[x];
	maintain(x);
	x=y;
}

void RR(int &x)
{
	int y=lch[x];
	lch[x]=rch[y];
	rch[y]=x;
	siz[y]=siz[x];
	maintain(x);
	x=y;
}

void ins(int &rt,int x)
{
	if(rt==0)
	{
		rt=++size;
		siz[rt]=1;
		cnt[rt]=1;
		val[rt]=x;
		rnd[rt]=rand();
		return;
	}
	siz[rt]++;
	if(val[rt]==x)
	{
		cnt[rt]++;
		return;
	}
	if(val[rt]<x)
	{
		ins(rch[rt],x);
		if(rnd[rch[rt]]<rnd[rt]) LR(rt);
		return;
	}
	if(val[rt]>x)
	{
		ins(lch[rt],x);
		if(rnd[lch[rt]]<rnd[rt]) RR(rt);
		return;
	}
}

void del(int &rt,int x)
{
	if(rt==0) return;
	if(val[rt]==x)
	{
		if(cnt[rt]>1)
		{
			cnt[rt]--;
			siz[rt]--;
		}
		else
		{
			int ll=lch[rt];
			int rr=rch[rt];
			if(ll==0||rr==0) rt=ll+rr;
			else
			{
				if(rnd[ll]<rnd[rr]) RR(rt);
				else LR(rt);
				del(rt,x);
			}
		}
	}
	else if(val[rt]<x)
	{
		siz[rt]--;
		del(rch[rt],x);
	}
	else
	{
		siz[rt]--;
		del(lch[rt],x);
	}
}

int getrnk(int rt,int x)
{
	if(rt==0) return 0;
	int ll=lch[rt];
	int rr=rch[rt];
	if(val[rt]==x) return siz[ll]+1;
	else if(x>val[rt]) return siz[ll]+cnt[rt]+getrnk(rr,x);
	else return getrnk(ll,x);
}

int getnum(int rt,int x)
{
	if(rt==0) return 0;
	int ll=lch[rt];
	int rr=rch[rt];
	if(x<=siz[ll]) return getnum(ll,x);
	x-=siz[ll];
	if(x<=cnt[rt]) return val[rt];
	x-=cnt[rt];
	return getnum(rr,x);
}

int getpre(int rt,int x)
{
	if(rt==0) return -INF;
	int ll=lch[rt];
	int rr=rch[rt];
	if(val[rt]<x)  return max(val[rt],getpre(rr,x));
	if(val[rt]>=x) return getpre(ll,x);
}

int getsuc(int rt,int x)
{
	if(rt==0) return INF;
	int ll=lch[rt];
	int rr=rch[rt];
	if(val[rt]<=x) return getsuc(rr,x);
	if(val[rt]>x)  return min(val[rt],getsuc(ll,x));
}

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&opt);
		scanf("%d",&tmp);
		if(opt==1) ins(rt,tmp);
		if(opt==2) del(rt,tmp);
		if(opt==3) printf("%d\n",getrnk(rt,tmp));
		if(opt==4) printf("%d\n",getnum(rt,tmp));
		if(opt==5) printf("%d\n",getpre(rt,tmp));
		if(opt==6) printf("%d\n",getsuc(rt,tmp));
	}
	return 0;
}
