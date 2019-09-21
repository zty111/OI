#include<bits/stdc++.h>
using namespace std;

const int N=20010;
const int M=200010;
const int INF=0x3f3f3f3f;

struct node
{
	int to;
	int nxt;
	int val;
	int w;
}edge[M];

int head[N];
int cnt=1;

void addedge(int x,int y,int f,int w)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].val=f;
	edge[cnt].w=w;
	head[x]=cnt;
}

bool vis[N];
int dis[N];
int s,t; 

bool SPFA()
{
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	deque<int>q;
	q.push_back(t);
	dis[t]=0;
	vis[t]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop_front();
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(edge[i^1].val)
			if(dis[v]>dis[x]-edge[i].w)
			{
				dis[v]=dis[x]-edge[i].w;
				if(vis[v]) continue;
				vis[v]=true;
				int u=q.front();
				if(!q.empty())
				if(dis[v]<dis[u])
				q.push_front(v);
				else q.push_back(v);
				else q.push_back(v);
			}
		}
		vis[x]=false;
	}
	return dis[s]!=INF;
}

int ans;

int DFS(int x,int maxf)
{
	if(x==t)
	{
		vis[t]=true;
		return maxf;
	}
	int tmp=0;
	vis[x]=true;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!vis[v])
		if(edge[i].val)
		if(dis[v]==dis[x]-edge[i].w)
		{
			int f=DFS(v,min(maxf-tmp,edge[i].val));
			if(f>0)
			{
				edge[i].val-=f;
				edge[i^1].val+=f;
				ans+=f*edge[i].w;
				tmp+=f;
			}
			if(tmp==maxf) break;
		}
	}
	return tmp;
}

int MCMF()
{
	int res=0;
	while(SPFA())
	{
		vis[t]=true;
		while(vis[t])
		{
			memset(vis,false,sizeof(vis));
			res+=DFS(s,INF);
		}
	}
	return res;
}

int t1,t2;
int t3,t4;
int m,n;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	scanf("%d",&t);
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		scanf("%d",&t3);
		scanf("%d",&t4);
		addedge(t1,t2,t3,t4);
		addedge(t2,t1,0,-t4);
	}
	printf("%d ",MCMF());
	printf("%d\n",ans);
	return 0;
}
