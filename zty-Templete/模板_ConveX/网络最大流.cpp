#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=200010;
const int INF=0x7f7f7f7f;

struct node
{
	int to;
	int nxt;
	int val;
}edge[M];

int head[N];
int cnt=1;

void addedge(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].val=w;
	head[x]=cnt;
}

int level[N];
int cur[N];
int s,t;
int ans;

bool makelevel()
{
	memset(level,0,sizeof(level));
	queue<int>q;
	while(!q.empty()) q.pop();
	level[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(edge[i].val)
			if(!level[v])
			{
				level[v]=level[x]+1;
				q.push(v);
			}
			
		}
	}
	return level[t];
}

int DFS(int x,int maxf)
{
	if(x==t) return maxf;
	for(int i=cur[x];i;i=edge[i].nxt)
	{
		cur[x]=i;
		int v=edge[i].to;
		if(edge[i].val)
		if(level[v]==level[x]+1)
		{
			int f=DFS(v,min(maxf,edge[i].val));
			if(f>0)
			{
				edge[i].val-=f;
				edge[i^1].val+=f;
				return f;
			}
		}
	}
	return 0;
}

void DINIC()
{
	while(makelevel())
	{
		memcpy(cur,head,sizeof(head));
		while(int tmp=DFS(s,INF)) ans+=tmp;
	}
}

int m,n;
int t1;
int t2;
int t3;

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
		addedge(t1,t2,t3);
		addedge(t2,t1,0);
	}
	DINIC();
	printf("%d\n",ans);
	return 0;
}
