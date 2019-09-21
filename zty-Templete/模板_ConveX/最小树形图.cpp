#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=110;
const int M=10010;
const int INF=0x3f3f3f3f; 

struct node
{
    int from;
    int to;
    int val;
}edge[M];

long long ans;
int idx[M];
int top[M];
int mis[M];
int fa[M];
int m,n,z;
int tot;

bool ZL()
{
	while(true)
	{
		memset(idx,0,sizeof(idx));
		memset(top,0,sizeof(top));
		memset(mis,0x3f,sizeof(mis));
		for(int i=1;i<=m;i++)
		{
			int tu=edge[i].from;
			int tv=edge[i].to;
			int tw=edge[i].val;
			if(tw<mis[tv])
			if(tu!=tv)
			{
				fa[tv]=tu;
				mis[tv]=tw;
			}
		}
		int r=0;
		mis[z]=0;
		for(int i=1;i<=n;i++)
		{
			if(mis[i]==INF) return false;
			ans+=mis[i];
			for(r=i;!idx[r];r=fa[r])
			{
				if(r==z) break;
				if(top[r]==i) break;
				top[r]=i;
			}
			if(r!=z)
			if(!idx[r])
			{
				idx[r]=++tot;
				for(int j=fa[r];;j=fa[j])
				{
					if(j==r) break;
					idx[j]=tot;
				}
			}
		}
		if(tot==0) return true;
		for(int i=1;i<=n;i++)
		{
			if(idx[i]) continue;
			idx[i]=++tot;
		}
		for(int i=1;i<=m;i++)
		{
			int tu=edge[i].from;
			int tv=edge[i].to;
			int tl=mis[tv];
			edge[i].from=idx[tu];
			edge[i].to=idx[tv];
			tu=edge[i].from;
			tv=edge[i].to;
			if(tu!=tv) edge[i].val-=tl;
		}
		n=tot;
		z=idx[z];
		tot=0;
	}
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&z);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&edge[i].from);
		scanf("%d",&edge[i].to);
		scanf("%d",&edge[i].val);
	}
	if(ZL()) printf("%lld\n",ans);
	else puts("-1");
	return 0;
}
