#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

struct Trie
{
	int fail;
	int cnt;
	int nxt[26];
}T[N];

int len;
int cnt;
int n;
char s[N];

void insert()
{
	int rt=0;
	for(int i=0;i<len;i++)
	{
		int x=s[i]-'a';
		if(!T[rt].nxt[x])
		T[rt].nxt[x]=++cnt;
		rt=T[rt].nxt[x];
	}
	T[rt].cnt++;
	return;
}

void BFS()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(T[0].nxt[i])
		{
			T[T[0].nxt[i]].fail=0;
			q.push(T[0].nxt[i]);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			int v=T[x].nxt[i];
			int f=T[x].fail;
			if(v)
			{
				T[v].fail=T[f].nxt[i];
				q.push(v);
			}
			else
			{
				T[x].nxt[i]=T[f].nxt[i];
			}
		}
	}
}

int query()
{
	int rt=0;
	int ans=0;
	for(int i=0;i<len;i++)
	{
		int x=s[i]-'a';
		rt=T[rt].nxt[x];
		for(int j=rt;j;j=T[j].fail)
		{
			if(T[j].cnt==-1) break;
			ans+=T[j].cnt;
			T[j].cnt=-1;
		}
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		len=strlen(s);
		insert();
	}
	T[0].fail=0;
	BFS();
	scanf("%s",s);
	len=strlen(s);
	printf("%d\n",query());
	return 0;
}
