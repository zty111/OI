#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=200010;
const int INF=2147483647;

inline int read()
{
	int X=0; char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) X=10*X+ch-'0',ch=getchar();
	return X;
}

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
	edge[cnt].val=w;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

struct data
{
	int u;
	int d;
}heap[M<<4];

bool operator <(data a,data b)
{
	return a.d>b.d;
}

int num;

void push(int a,int b)
{
	heap[++num]=(data){a,b};
	for(int i=num,d=i>>1;d;)
	{
		if(heap[i]<heap[d])
		swap(heap[i],heap[d]);
		else break;
		i=d;
		d=i>>1;
	}
}

void pop()
{
	heap[1]=heap[num--];
	for(int i=2,d=1;i<=num;)
	{
		if(heap[i+1]<heap[i])
		if(i<num) i++;
		if(heap[i]<heap[d])
		swap(heap[i],heap[d]);
		else break;
		d=i;
		i=d<<1;
	}
}

data top()
{
	return heap[1];
}

int n,m,s;
int dis[N];

void Dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		if(i==s) dis[i]=0;
		else dis[i]=INF;
	}
	push(s,0);
	while(num)
	{
		data cur=top();
		pop();
		int x=cur.u;
		int d=cur.d;
		if(d==dis[x])
		{
			for(int i=head[x];i;i=edge[i].nxt)
			{
				int v=edge[i].to;
				if(dis[v]>dis[x]+edge[i].val)
				{
					dis[v]=dis[x]+edge[i].val;
					push(v,dis[v]);
				}
			}
		}
	}
}

int t1;
int t2;
int t3;

int main()
{
	n=read();
	m=read();
	s=read();
	for(int i=1;i<=m;i++)
	{
		t1=read();
		t2=read();
		t3=read();
		addedge(t1,t2,t3);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
	printf("%d ",dis[i]);
	puts("");
	return 0;
}
