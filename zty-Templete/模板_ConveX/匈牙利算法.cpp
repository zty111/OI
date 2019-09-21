#include<bits/stdc++.h>
using namespace std;

const int N=2010;
const int M=4000010;

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

bool vis[N];
int mak[N];

bool DFS(int x)
{
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(vis[v]) continue;
		vis[v]=true;
		if(!mak[v])
		{
			mak[v]=x;
			return true;
		}
		if(DFS(mak[v]))
		{
			mak[v]=x;
			return true;
		}
	}
	return false;
}

int m,n,p;
int t1,t2;
int ans;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		if(t1>n) continue;
		if(t2>m) continue;
		addedge(t1,t2);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(DFS(i)) ++ans;		
	}
	printf("%d\n",ans);
	return 0;
}
