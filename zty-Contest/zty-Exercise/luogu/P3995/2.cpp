#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;
int n,q,fa[MAXN],deep[MAXN],size[MAXN],top[MAXN],son[MAXN];
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt;

inline int read()
{
	int x=0; char c=getchar();
	while(c>'9'||c<'0')	c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}

inline void add(int u,int v)
{
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	return ;
}

inline void dfs(int x,int Fa)
{
	size[x]=1; fa[x]=Fa; deep[x]=deep[Fa]+1;
	int temp=-1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==Fa) continue;
		dfs(v,x);
		size[x]+=size[v];
		if(size[v]>temp)
		{
            temp=size[v];
            son[x]=v;
        }
	}
	return ;
}

inline void dfs2(int x,int Fa)
{
	int temp=-1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==Fa) continue;
		dfs2(v,x);
		size[x]+=size[v];
		if(size[v]>temp)
		{
            temp=size[v];
            son[x]=v;
        }
	}
	return ;
}

inline void dfs1(int x,int tp)
{
	top[x]=tp;
	if(son[x]==0) return;
	dfs1(son[x],tp);
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[x]||v==son[x]) continue;
		dfs1(v,v);
	}
	return ;
}

inline int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return deep[x]<deep[y]?x:y;
}

int main(void)
{
	n=read(); q=read(); int x,y;
	for(int i=1;i<=n-1;++i)
	{
		x=read(); y=read();
		add(x,y); add(y,x);
	} 
	dfs(1,0); dfs1(1,1);
	memset(size,0,sizeof(size));
	memset(son,0,sizeof(son));
	for(int i=1;i<=q;++i)
	{
		x=read(); y=read();
		int lca=LCA(x,y);
		if(fa[x]!=lca) size[x]++,size[lca]--;
		if(fa[y]!=lca) size[y]++,size[lca]--;
	}
	dfs2(1,0);
	for(int i=1;i<=n;++i) printf("%d\n",son[i]);
	return 0;
}