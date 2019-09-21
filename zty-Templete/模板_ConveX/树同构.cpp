#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2010;
const int B=2333;

struct node
{
    int to;
    int nxt;
}edge[N];

ll ans[N][N];
int head[N];
int m,n,T;
int tmp;
int cnt;


void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

long long DFS(int x,int fa)
{
	ll T[N];
	ll ans=N;
	int top=0;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa) continue;
		T[++top]=DFS(v,x);
	}
	sort(T+1,T+top+1);
	for(int i=1;i<=top;i++)
	{
		ans*=B;
		ans+=T[i];
	}
	return ans*B+N+1;
}

int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		cnt=0;
		memset(head,0,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			if(tmp==0) continue;
			addedge(tmp,i);
			addedge(i,tmp);
		}
		for(int i=1;i<=n;i++)
		{
			ll x=DFS(i,0);
			ans[t][i]=x;
		}
		sort(ans[t]+1,ans[t]+n+1);
		for(int i=1,j=0;i<=t;i++)
		{
			while(j<=n)
			{
				j++;
				ll t1=ans[t][j];
				ll t2=ans[i][j];
				if(t1!=t2) break;
			}
			if(j>n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
    return 0;
}
