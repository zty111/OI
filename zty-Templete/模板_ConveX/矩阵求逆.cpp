#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1010;
const int mod=1000000007;

int n;
ll T[N][N];

int FP(int a,int k)
{
	int ans=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) ans=1LL*a*ans%mod;
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%lld",&T[i][j]);
	for(int i=1;i<=n;i++) T[i][i+n]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!T[j][i]) continue;
			for(int k=1;k<=n*2;k++)
			swap(T[i][k],T[j][k]);
			break;
		}
		if(!T[i][i])
		{
			puts("No Solution");
			return 0;
		}
		int inv=FP(T[i][i],mod-2);
		for(int j=i;j<=n*2;j++)
		T[i][j]=1LL*T[i][j]*inv%mod;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			inv=T[j][i];
			for(int k=1;k<=n*2;k++)
			T[j][k]=(1LL*T[j][k]-1LL*inv*T[i][k]%mod+mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		printf("%lld ",T[i][j+n]);
		puts("");
	}
	return 0;
}
