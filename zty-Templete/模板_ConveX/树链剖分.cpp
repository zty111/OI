#include<bits/stdc++.h>
using namespace std;

const int N=400010;
const int M=800010;

struct node
{
	int to;
	int nxt;
}T[N];

int head[N];
int cnt;

void addedge(int x,int y)
{
	T[++cnt].to=y;
	T[cnt].nxt=head[x];
	head[x]=cnt;
}

#define ls rt<<1
#define rs rt<<1|1

long long add[M];
long long sum[M];
int dfn[N];
int arr[N];
int siz[N];
int dep[N];
int son[N];
int end[N];
int top[N];
int pos[N];
int fa[N];
int tot=1;
int num=1;

void maintain(int rt)
{
	sum[rt]=sum[ls]+sum[rs];
}

void pushdown(int rt,int k)
{
	if(!add[rt]) return;
	add[ls]+=add[rt];
	add[rs]+=add[rt];
	sum[ls]+=add[rt]*(k-(k>>1));
	sum[rs]+=add[rt]*(k>>1);
	add[rt]=0;
}

void build(int rt,int l,int r)
{
	if(l==r)
	{
		sum[rt]=arr[dfn[num++]];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	maintain(rt);
}

void update(int rt,int l,int r,int ql,int qr,int k)
{
	if(ql<=l)
	if(qr>=r)
	{
		add[rt]+=k;
		sum[rt]+=1LL*k*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,r-l+1);
	if(ql<=mid)  update(ls,l,mid,ql,qr,k);
	if(qr>mid) update(rs,mid+1,r,ql,qr,k);
	maintain(rt);
}

long long query(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l)
	if(qr>=r) return sum[rt];
	pushdown(rt,r-l+1);
	long long res=0;
	int mid=(l+r)>>1;
	if(ql<=mid)  res+=query(ls,l,mid,ql,qr);
	if(qr>mid) res+=query(rs,mid+1,r,ql,qr);
	return res;
}

void DFS1(int x)
{
	int sz=0;
	for(int i=head[x];i;i=T[i].nxt)
	{
		int v=T[i].to;
		if(v==fa[x]) continue;
		dep[v]=dep[x]+1;
		fa[v]=x;
		siz[x]++;
		DFS1(v);
		siz[x]+=siz[v];
		if(siz[v]>sz)
		{
			son[x]=v;
			sz=siz[v];
		}
	}
}

void DFS2(int x,int st)
{
	bool jud=true;
	if(son[x])
	{
		jud=false;
		top[son[x]]=st;
		dfn[tot++]=son[x];
		DFS2(son[x],st);
	}
	for(int i=head[x];i;i=T[i].nxt)
	{
		int v=T[i].to;
		if(v==fa[x]) continue;
		if(v==son[x]) continue;
		if(jud)
		{
			top[v]=st;
			jud=false;
		}
		else top[v]=v;
		dfn[tot++]=v;
		DFS2(v,v);
	}
	end[x]=tot-1;
	return;
}

long long mod;
long long ans;
int root;
int m,n;
int opt;
int t1;
int t2;
int t3;

void update_path(int x,int y,int w)
{
	int fx=top[x];
	int fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]>dep[fy])
		{
			update(1,1,n,pos[fx],pos[x],w);
			x=fa[fx];
		}
		else
		{
			update(1,1,n,pos[fy],pos[y],w);
			y=fa[fy];
		}
		fx=top[x];
		fy=top[y];
	}
	if(x!=y)
	{
		if(pos[x]<pos[y]) update(1,1,n,pos[x],pos[y],w);
		else update(1,1,n,pos[y],pos[x],w);
	}
	else update(1,1,n,pos[x],pos[y],w);
}

long long query_path(int x,int y)
{
	long long ret=0;
	int fx=top[x];
	int fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]>dep[fy])
		{
			ret+=query(1,1,n,pos[fx],pos[x]);
			x=fa[fx];
		}
		else 
		{
			ret+=query(1,1,n,pos[fy],pos[y]);
			y=fa[fy];
		}
		fx=top[x];
		fy=top[y];
	}
	if(x!=y)
	{
		if(pos[x]<pos[y]) ret+=query(1,1,n,pos[x],pos[y]);
		else ret+=query(1,1,n,pos[y],pos[x]);
	}
	else ret+=query(1,1,n,pos[x],pos[y]);
	return ret;
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&root);
	scanf("%lld",&mod);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		addedge(t1,t2);
		addedge(t2,t1);
	}
	fa[root]=root;
	dep[root]=1;
	DFS1(root);
	top[root]=root;
	dfn[tot++]=root;
	DFS2(root,root);
	for(int i=1;i<tot;i++) pos[dfn[i]]=i;
	build(1,1,n);
	while(m--)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			scanf("%d",&t3);
			update_path(t1,t2,t3);
		}
		if(opt==2)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			ans=query_path(t1,t2);
			printf("%lld\n",ans%mod);
		}
		if(opt==3)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			update(1,1,n,pos[t1],end[t1],t2);
		}
		if(opt==4)
		{
			scanf("%d",&t1);
			ans=query(1,1,n,pos[t1],end[t1]);
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
}
