#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=200010;

struct node
{
	int to;
	int nxt;
	int val;
}edge[M];

int head[N];
int cnt;

void addedge(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].val=w;
	head[x]=cnt;
}

bool vis[N];
int tot[N];
int dis[N];
int T,m,n;

void SPFA(int rt)
{
	queue<int>q;
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(tot,0,sizeof(tot));
	memset(dis,0x3f,sizeof(dis));
	q.push(rt);
	dis[rt]=1;
	vis[rt]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=false;
		if(tot[x]>=n)
		{
			puts("YE5");
			return;
		}
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[x]+edge[i].val)
			{
				dis[v]=dis[x]+edge[i].val;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
					tot[v]++;
					if(tot[v]>=n)
					{
						puts("YE5");
						return;
					}
				}
			}
		}
	}
	puts("N0");
	return;
}

int t1;
int t2;
int t3;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		memset(head,0,sizeof(head));
		cnt=0; 
		while(m--)
		{
			scanf("%d",&t1);
			scanf("%d",&t2);
			scanf("%d",&t3);
			addedge(t1,t2,t3);
			if(t3<0) continue;
			addedge(t2,t1,t3);
		}
		SPFA(1);
	}
	return 0;
}
