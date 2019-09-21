#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2000010;
const int P=25;

struct SAM_node
{
	int nxt[P+1];
	int fa;
}T[N<<1];

int las=1;
int cnt=1;
int siz[N];
int len[N];
int a[N];
int c[N];
ll ans;

namespace SAM
{
	void insert(int x)
	{
		int cur=las;
		int np=++cnt;
		las=np;
		len[np]=len[cur]+1;
		for(;cur;cur=T[cur].fa)
		{
			if(T[cur].nxt[x]) break;
			T[cur].nxt[x]=np;
		}
		if(!cur) T[np].fa=1;
		else
		{
			int q=T[cur].nxt[x];
			if(len[cur]+1==len[q]) T[np].fa=q;
			else
			{
				int nq=++cnt;
				len[nq]=len[cur]+1;
				for(int i=0;i<=P;i++)
				T[nq].nxt[i]=T[q].nxt[i];
				T[nq].fa=T[q].fa;
				T[np].fa=T[q].fa=nq;
				for(;;cur=T[cur].fa)
				{
					if(T[cur].nxt[x]!=q) break;
					T[cur].nxt[x]=nq;
				}
			}
		}
		siz[np]=1;
	}
	
	void calc()
	{
		for(int i=1;i<=cnt;i++) c[len[i]]++;
		for(int i=1;i<=cnt;i++) c[i]+=c[i-1];
		for(int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
		for(int i=cnt;i;i--)
		{
			int cur=a[i];
			siz[T[cur].fa]+=siz[cur];
			if(siz[cur]>1) ans=max(ans,1LL*siz[cur]*len[cur]);
		}
		printf("%lld\n",ans);
		return;
	}
}
using namespace SAM;

char s[N];
int n;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) insert(s[i]-'a');
	calc();
	return 0;
}
