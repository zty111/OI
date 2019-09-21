// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,k;
ll mod;

ll read(ll mod)
{
	ll X=0,opt=0; char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		X=10LL*X+ch-'0';
		if(X>=mod) opt=1;
		X%=mod;
		ch=getchar();
	}
	if(opt) X+=mod;
	return X;
}

ll FP(ll a,ll k,ll mod)
{
	ll ans=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) ans=1LL*a*ans%mod;
	return ans;
}

ll getphi(ll x)
{
	ll ans=x;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i) continue;
		ans=ans/i*(i-1);
		while(x%i==0) x/=i;
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}

int main()
{
	scanf("%lld",&a);
	scanf("%lld",&mod);
	k=read(getphi(mod));
	printf("%lld\n",FP(a,k,mod));
	return 0;
}
