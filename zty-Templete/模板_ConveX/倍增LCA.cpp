#include<bits/stdc++.h>
using namespace std;

const int N=500010;
const int M=1000010;
const int P=20; 

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

int anc[N][P+1];
int dep[N];

void DFS(int x,int deep)
{
	for(int i=1;i<=P;i++)
	{
		if(dep[x]<(1<<i)) break;
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(anc[x][0]==v) continue;
		anc[v][0]=x;
		dep[v]=deep+1;
		DFS(v,deep+1);
	}
	return;
}

int LCA(int x,int y)
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
	anc[s][0]=s;
	dep[s]=0;
	DFS(s,0);
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		int ans=LCA(t1,t2);
		printf("%d\n",ans);
	}
	return 0;
}
