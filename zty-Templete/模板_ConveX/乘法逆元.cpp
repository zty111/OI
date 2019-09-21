#include<bits/stdc++.h>
using namespace std;

const int N=3000010;

int n;
int mod;
int inv[N];

int main()
{
	scanf("%d",&n);
	scanf("%d",&mod);
	inv[1]=1;
	for(int i=2;i<=n;i++)
	inv[i]=(1LL*(mod-mod/i)*inv[mod%i])%mod;
	for(int i=1;i<=n;i++)
	printf("%d\n",inv[i]);
	return 0;
}
