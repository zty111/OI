#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
typedef long long ll;

ll T,n;

struct Matrix
{
	ll T[4][4];
}E,P;

Matrix mul(Matrix X,Matrix Y)
{
	Matrix Z;
	memset(Z.T,0,sizeof(Z.T));
	for(int i=1;i<=3;i++)
	for(int k=1;k<=3;k++)
	for(int j=1;j<=3;j++)
	{
		ll tmp=0;
		tmp=(tmp+Z.T[i][j])%mod;
		tmp=(tmp+X.T[i][k]*Y.T[k][j])%mod;
		Z.T[i][j]=tmp;
	}
	return Z;
}

Matrix pow(Matrix M,ll k)
{
	Matrix ans=E;
	for(;k;k>>=1,M=mul(M,M))
	if(k&1) ans=mul(ans,M);
	return ans;
}

int main()
{
	E.T[1][1]=1;
	E.T[3][1]=1;
	E.T[1][2]=1;
	E.T[2][3]=1;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("1");
			continue;
		}
		memset(P.T,0,sizeof(P.T));
		P=pow(E,n-2);
		printf("%lld\n",P.T[1][1]);
	}
	return 0;
}

