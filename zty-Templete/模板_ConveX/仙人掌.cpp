#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M=200010;
const int N=20010;
const int P=21;

struct node
{
	int to;
	int nxt;
	ll val;
}edge[M];

int head1[N];
int head2[N];
int cnt;

void addedge(int *head,int x,int y,ll w)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].val=w;
	head[x]=cnt;
}

int anc[N][P+1];
int dfn[N];
int low[N];
int dep[N];
ll dis[N];
ll siz[N];
int num;
int tot;

void DFS(int x)
{
	tot++;
	dfn[x]=tot;
	low[x]=tot;
	for(int i=head1[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==anc[x][0]) continue;
		if(!dfn[v])
		{
			anc[v][0]=x;
			dis[v]=dis[x]+edge[i].val;
			DFS(v);
			low[x]=min(low[x],low[v]);
		}
		else
		{
			low[x]=min(low[x],dfn[v]);
			if(dfn[v]>=dfn[x]) continue;
			num++;
			addedge(head2,num,v,0);
			addedge(head2,v,num,0);
			ll len=edge[i].val;
			for(int j=x;;j=anc[j][0])
			{
				if(j==v) break;
				len+=dis[j];
				len-=dis[anc[j][0]];
			}
			siz[num]=len;
			ll tmp=edge[i].val;
			for(int j=x;;j=anc[j][0])
			{
				if(j==v) break;
				ll w=min(tmp,len-tmp);
				addedge(head2,num,j,w);
				addedge(head2,j,num,w);
				siz[j]=tmp;
				tmp+=dis[j];
				tmp-=dis[anc[j][0]];
			}
		}
		if(low[v]>dfn[x])
		{
			int w=edge[i].val;
			addedge(head2,x,v,w);
			addedge(head2,v,x,w);
		}
	}
}

void DFS1(int x,int f)
{
	dep[x]=dep[f]+1;
	anc[x][0]=f;
	for(int i=head2[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==f) continue;
		dis[v]=dis[x]+edge[i].val;
		DFS1(v,x);
	}
}

int LCA(int &x,int &y)
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

int m,n,q;

ll solve(int x,int y)
{
	ll rt=dis[x]+dis[y];
	int lca=LCA(x,y);
	rt-=(dis[lca]<<1);
	if(lca>n)
	{
		ll p=dis[x]-dis[lca];
		ll q=dis[y]-dis[lca];
		rt-=p;
		rt-=q;
		ll tmp=abs(siz[x]-siz[y]);
		rt+=min(siz[lca]-tmp,tmp);
	}
	return rt;
}

int t1,t2;
ll t3;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&q);
	num=n;
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		scanf("%lld",&t3);
		addedge(head1,t1,t2,t3);
		addedge(head1,t2,t1,t3);
	}
	anc[1][0]=0;
	DFS(1);
	for(int i=1;i<=num;i++)
	{
		dep[i]=0;
		dis[i]=0;
	}
	DFS1(1,0);
	for(int j=1;j<=P;j++)
	for(int i=1;i<=num;i++)
	{
		int v=anc[i][j-1];
		anc[i][j]=anc[v][j-1];
	}
	while(q--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		t3=solve(t1,t2);
		printf("%lld\n",t3);
	}
	return 0;
}
