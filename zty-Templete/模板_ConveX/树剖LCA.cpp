#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int M=1000010;

struct node
{
	int to;
	int nxt;
}edge[M];

int head[N];
int cnt;

void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

int siz[N];
int dep[N];
int fa[N];
int son[N];
int top[N];
bool vis[N];

void DFS1(int x,int f)
{
	siz[x]=1;
	vis[x]=true;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==f) continue;
		dep[v]=dep[x]+1;
		fa[v]=x;
		DFS1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
		son[x]=v;
	}
}

void DFS2(int x,int tp)
{
	top[x]=tp;
	if(son[x]) DFS2(son[x],tp);
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==son[x]) continue;
		if(v==fa[x]) continue;
		DFS2(v,v);
	}
}

int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		int t1=top[u];
		int t2=top[v];
		if(dep[t1]>dep[t2]) u=fa[t1];
		if(dep[t1]<=dep[t2]) v=fa[t2];
	}
	if(dep[u]<dep[v]) return u;
	if(dep[u]>=dep[v]) return v;
}

int n,m,s;
int t1;
int t2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		addedge(t1,t2);
		addedge(t2,t1);
	}
	DFS1(s,0);
	DFS2(s,s);
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		int ans=LCA(t1,t2);
		printf("%d\n",ans);
	}
	return 0;
}
