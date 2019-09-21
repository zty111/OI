#include<bits/stdc++.h>
using namespace std;

const int N=200010;

struct data
{
	int x;
	int y;
	int w;
}P[N];
 
int fa[N]; 
 
int find(int k)
{
	if(fa[k]==k) return fa[k];
	return fa[k]=find(fa[k]);
}

bool cmp(data a,data b)
{
	if(a.w==b.w)
	return a.x>b.x;
	return a.w<b.w;
}

int m,n;
int cnt;
int ans;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&P[i].x);
		scanf("%d",&P[i].y);
		scanf("%d",&P[i].w);
	}
	sort(P+1,P+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int t1=P[i].x;
		int t2=P[i].y;
		int tw=P[i].w;
		int p1=find(t1);
		int p2=find(t2);
		if(p1==p2) continue;
		ans+=tw;
		fa[p1]=p2;
		cnt++;
		if(cnt==n-1) break;
	}
	printf("%d\n",ans);
	return 0;
}
