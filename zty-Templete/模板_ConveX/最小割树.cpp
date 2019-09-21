#include<bits/stdc++.h>
using namespace std;

const int P=9;
const int N=3010;
const int INF=0x3f3f3f3f;

struct node
{
	int to;
	int nxt;
	int val;
}edge[N];

int head[N];
int cnt=1;
int T[N];

void addedge(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].val=w;
	head[x]=cnt;
}

int n,m,q;

namespace GHT
{
	struct node
	{
		int to;
		int nxt;
		int val;
		int w;
	}edge[N];
    
    int head[N];
    int cnt=1;
    
    void addedge(int x,int y,int w)
    {
    	edge[++cnt].to=y;
    	edge[cnt].nxt=head[x];
    	edge[cnt].val=0;
    	edge[cnt].w=w;
    	head[x]=cnt;
	}
    
    int level[N];
    int cur[N];
    int s,t;
    
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
    			if(edge[i].w>edge[i].val)
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
        int tmp=0;
        for(int i=cur[x];i;i=edge[i].nxt)
        {
            cur[x]=i;
            int v=edge[i].to;
            if(edge[i].w>edge[i].val)
            if(level[v]==level[x]+1)
            {
                int f=DFS(v,min(maxf,edge[i].w-edge[i].val));
                if(f>0)
                {
                	maxf-=f;
                	tmp+=f;
                    edge[i].val+=f; 
                    edge[i^1].val-=f;
                }
            }
        }
        return tmp;
    }
    
    int DINIC(int x,int y)
    {
    	int ans=0;
    	s=x;
    	t=y;
    	for(int i=2;i<=cnt;i++) edge[i].val=0;
    	while(makelevel())
    	{
    		memcpy(cur,head,sizeof(head));
    		while(int tmp=DFS(s,INF)) ans+=tmp;
		}
		return ans;
	}
	
	int col[N];
	int bin[N];
	int tot;
	
	void DFS2(int x,int k)
	{
		col[x]=k;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(edge[i].w>edge[i].val)
			if(col[v]!=k) DFS2(v,k); 
		}
	}
	
	void build(int l,int r)
	{
		if(l==r) return;
		int t1=T[l];
		int t2=T[l+1];
		int tw=DINIC(t1,t2);
		DFS2(t1,++tot);
		int L=l,R=r;
		for(int i=l;i<=r;i++)
		{
			int x=T[i];
			if(col[x]==tot) bin[L++]=T[i];
			else bin[R--]=T[i];
		}
		for(int i=l;i<=r;i++) T[i]=bin[i];
		::addedge(t1,t2,tw);
		::addedge(t2,t1,tw);
		build(l,L-1);
		build(R+1,r);
	}
}

int anc[N][P+1];
int mis[N][P+1];
int dep[N];

void DFS(int x)
{
	for(int i=1;i<=P;i++)
	{
		anc[x][i]=anc[anc[x][i-1]][i-1];
		mis[x][i]=min(mis[x][i-1],mis[anc[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(anc[x][0]==v) continue;
		dep[v]=dep[x]+1;
		anc[v][0]=x;
		mis[v][0]=edge[i].val;
		DFS(v);
	}
}

int solve(int x,int y)
{
	int ans=INF;
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=P;~i;i--)
	{
		if(d&(1<<i))
		{
			ans=min(ans,mis[x][i]);
			x=anc[x][i];
		}
 	}
	if(x==y) return ans;
	for(int i=P;~i;i--)
	{
		if(anc[x][i]!=anc[y][i])
		{
			ans=min(ans,mis[x][i]);
			ans=min(ans,mis[y][i]);
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	ans=min(ans,mis[x][0]);
	ans=min(ans,mis[y][0]);
	return ans;
}

int t1,t2,t3;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		scanf("%d",&t3);
		GHT::addedge(t1,t2,t3);
		GHT::addedge(t2,t1,t3);
	}
	for(int i=1;i<=n;i++) T[i]=i;
	GHT::build(1,n);
	dep[1]=1;
	DFS(1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		int ans=solve(t1,t2);
		printf("%d\n",ans);
	}
	return 0;
}
