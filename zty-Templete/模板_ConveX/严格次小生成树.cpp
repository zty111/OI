#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int P=21;
const int N=500010;
const int M=2000010;
const ll INF=0x3f3f3f3f3f3f3f3fLL;

struct node
{
	int from;
	int to;
	int nxt;
	int val;
}edge[M];


struct data
{
	int u;
	int v;
	int w;
}T[M];

int head[N];
int cnt;

void addedge(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].from=x;
	edge[cnt].val=w;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

int anc[N][P+1];
ll mis[N][P+1];
ll mas[N][P+1];
bool jud[N];
int dep[N];
int n,m;

void BFS()
{
	queue<int>q;
	while(!q.empty()) q.pop();
	q.push(1);
	jud[1]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		jud[x]=true;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(jud[v]) continue;
			jud[v]=true;
			dep[v]=dep[x]+1;
			anc[v][0]=x;
			mas[v][0]=edge[i].val;
			mis[v][0]=-INF;
			q.push(v);
		}
	}
}

void LCA()
{
	for(int i=1;i<=P;i++)
	for(int j=1;j<=n;j++)
	{
		int v=anc[j][i-1];
		anc[j][i]=anc[v][i-1];
		mas[j][i]=max(mas[j][i-1],mas[v][i-1]);
		mis[j][i]=max(mis[j][i-1],mis[v][i-1]);
		if(mas[j][i-1]>mas[v][i-1])
		mis[j][i]=max(mis[j][i],mas[v][i-1]);
		else if(mas[j][i-1]<mas[v][i-1])
		mis[j][i]=max(mis[j][i],mas[j][i-1]);
	}
}

int solve(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=P;~i;i--)
	{
		if(d&(1<<i))
		x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=P;~i;i--)
	{
		if(anc[x][i]!=anc[y][i])
		{
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

ll query(int x,int y,int k)
{
	ll ans=-INF;
	for(int i=P;~i;i--)
	{
		if(dep[anc[x][i]]>=dep[y])
		{
			if(k!=mas[x][i])
			ans=max(ans,mas[x][i]);
			else ans=max(ans,mis[x][i]);
			x=anc[x][i];
		}
	}
	return ans;
}

int fa[N];
bool vis[N];

bool cmp(data x,data y)
{
	return x.w<y.w;
}

int find(int x)
{
	if(x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&T[i].u);
		scanf("%d",&T[i].v);
		scanf("%d",&T[i].w);
	}
	sort(T+1,T+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int t1=T[i].u;
		int t2=T[i].v;
		int tw=T[i].w;
		int p1=find(t1);
		int p2=find(t2);
		if(p1==p2) continue;
		ans+=tw;
		fa[p1]=p2;
		addedge(t1,t2,tw);
		addedge(t2,t1,tw);
		vis[i]=true;
	}
	anc[1][0]=-1;
	mis[1][0]=-INF;
	dep[1]=1;
	BFS();
	LCA();
	ll res=INF;
	for(int i=1;i<=m;i++)
	{
		if(vis[i]) continue;
		int t1=T[i].u;
		int t2=T[i].v;
		int tw=T[i].w;
		int tt=solve(t1,t2);
		int masx=query(t1,tt,tw);
		int masy=query(t2,tt,tw);
		ll tmp=ans+tw;
		tmp-=max(masx,masy);
		res=min(tmp,res);
	}
	printf("%lld\n",res);
	return 0;
}
