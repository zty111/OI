#include<bits/stdc++.h>
using namespace std;

const int N=2000010;
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

int m,n;
int top;
int tot;
int stk[N];
int jud[N];
int dfn[N];
int low[N];
int col[N];

void tarjan(int x)
{
	top++;
	tot++;
	stk[top]=x;
	jud[x]=true;
	low[x]=tot;
	dfn[x]=tot;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
			continue;
		}
		if(jud[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		tot++;
		while(stk[top+1]!=x)
		{
			col[stk[top]]=tot;
			jud[stk[top--]]=false;
		}
	}
}

int t1;
int t2;
int l1;
int l2;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t1);
		scanf("%d",&l1);
		scanf("%d",&t2);
		scanf("%d",&l2);
		int p1=t1+n-l1*n;
		int p2=t2+l2*n;
		int p3=t2+n-l2*n;
		int p4=t1+l1*n;
		addedge(p1,p2);
		addedge(p3,p4);
	}
	for(int i=1;i<=n*2;i++)
	if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
	{
		if(col[i]==col[n+i])
		return puts("IMPOSSIBLE"),0;
	}
	puts("POSSIBLE");
	for(int i=1;i<=n;i++)
	{
		if(col[i]>col[n+i]) printf("1 ");
		else printf("0 ");
	}
	puts("");
	return 0;
}
