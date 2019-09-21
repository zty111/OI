#include<bits/stdc++.h>
using namespace std;

const int N=10010;

int fa[N];

int find(int k)
{
	if(fa[k]==k) return fa[k];
	return fa[k]=find(fa[k]);
}

int m,n;
int opt;
int t1;
int t2; 

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	while(m--)
	{
		scanf("%d",&opt);
		scanf("%d",&t1);
		scanf("%d",&t2);
		if(opt==1)
		{
			int p1=find(t1);
			int p2=find(t2);
			fa[p1]=p2;
		}
		if(opt==2)
		{
			int p1=find(t1);
			int p2=find(t2);
			if(p1==p2) puts("Y");
			if(p1!=p2) puts("N");
		}
	}
	return 0;
}
