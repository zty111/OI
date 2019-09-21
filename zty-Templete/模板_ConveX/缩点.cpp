#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=200010;

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

int sta[N];
int jud[N];
int dfn[N];
int low[N];
int col[N];
int sum[N];
int val[N];
int dp[N];
int idx;
int top;
int tot;

void tarjan(int x)
{
	idx++;
	top++;
	sta[top]=x;
	jud[x]=true;
	dfn[x]=idx;
	low[x]=idx;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(jud[v])
		{
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x])
	{
		tot++;
		while(sta[top+1]!=x)
		{
			col[sta[top]]=tot;
			sum[tot]+=val[sta[top]];
			jud[sta[top--]]=false;
		}
	}
}

void search(int x)
{
	if(dp[x]) return;
	dp[x]=sum[x];
	int mas=0;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!dp[v]) search(v);
		mas=max(mas,dp[v]);
	}
	dp[x]+=mas;
}

int m,n;
int ans;
int tx[N];
int ty[N];

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&val[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&tx[i]);
		scanf("%d",&ty[i]);
		addedge(tx[i],ty[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]) continue;
		tarjan(i);
	}
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		int dx=tx[i];
		int dy=ty[i];
		if(col[dx]==col[dy]) continue;
		addedge(col[dx],col[dy]);
	}
	for(int i=1;i<=tot;i++)
	{
		if(dp[i]) continue;
		search(i);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
