#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2010;
const int mod=998244353;

int P(int x,int y)
{
	ll t1=x;
	ll t2=y;
	ll tw=t1+t2;
	if(tw>=mod) return tw-mod;
	return tw;
}

int S(int x,int y)
{
	ll t1=x+mod;
	ll t2=y;
	ll tw=t1-t2;
	if(tw<0) return tw+mod;
	return tw;
}

int FP(int a,int k)
{
	int res=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) res=1LL*a*res%mod;
	return res;
}

int n,k;
int A[N];
int B[N];
int ans;

int main()
{
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		scanf("%d",&B[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			tmp=1LL*tmp*S(A[i],A[j])%mod;
		}
		tmp=FP(tmp,mod-2);
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			tmp=1LL*tmp*S(k,A[j])%mod;
		}
		tmp=1LL*tmp*B[i]%mod;
		ans=P(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
