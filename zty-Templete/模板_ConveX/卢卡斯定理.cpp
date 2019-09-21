#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int T,m,n;
int mod;
int inv[N];
int fac[N];

int Lucas(int n,int m)
{
	if(n<m) return 0;
	if(n<mod)
	{
		int ans=1;
		ans=1LL*ans*fac[n]%mod;
		ans=1LL*ans*inv[m]%mod;
		ans=1LL*ans*inv[n-m]%mod;
		return ans;
	}
	int ans=1;
	ans=1LL*ans*Lucas(n/mod,m/mod)%mod;
	ans=1LL*ans*Lucas(n%mod,m%mod)%mod;
	return ans;
}

int main()
{
	inv[0]=1;
	inv[1]=1;
	fac[0]=1;
	fac[1]=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		scanf("%d",&mod);
		for(int i=2;i<=m+n;i++)
		{
			inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
		}
		for(int i=2;i<=m+n;i++)
		{
			inv[i]=1LL*inv[i-1]*inv[i]%mod;
			fac[i]=1LL*fac[i-1]*i%mod;
		}
		int ans=Lucas(m+n,m);
		printf("%d\n",ans);
	}
	return 0;
}
