#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=200010;

struct node
{
	int nxt;
	int to;
}edge[M];

int head[N];
int cnt;

void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

bool cut[N];
int dfn[N];
int low[N];
int ans;
int idx;
int m,n;
int t1;
int t2;

void tarjan(int x,int f)
{
	idx++;
	dfn[x]=idx;
	low[x]=idx;
	int num=0;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v,f);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x])
			if(x!=f) cut[x]=true;
			if(x==f) num++;
		}
		if(dfn[v]<low[x]) low[x]=dfn[v];
	}
	if(num>1)
	if(x==f) cut[x]=true;
	return;
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		addedge(t1,t2);
		addedge(t2,t1);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]) continue;
		tarjan(i,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!cut[i]) continue;
		ans++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(!cut[i]) continue;
		printf("%d ",i);
	}
	puts("");
	return 0;
}
