#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;

ll a[N];
ll b[N];
int n;

ll mul(ll a,ll k,ll mod)
{
	ll res=0;
	for(;k;k>>=1,a=(a+a)%mod)
	if(k&1)  res=(res+a)%mod;
	return res;
}

ll ExGCD(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll gcd=ExGCD(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return gcd;
}

ll ExCRT()
{
	ll x,y,k;
	ll m=b[1];
	ll ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ll t1=m;
		ll t2=b[i];
		ll t3=(a[i]-ans%t2+t2)%t2;
		ll gcd=ExGCD(t1,t2,x,y);
		ll tg=t2/gcd;
		if(t3%gcd) return -1;
		x=mul(x,t3/gcd,tg);
		ans+=x*m;
		m*=tg;
		ans=(ans%m+m)%m;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",ExCRT());
	return 0;
}
