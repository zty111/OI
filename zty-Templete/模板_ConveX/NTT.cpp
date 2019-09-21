#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=20000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int PR=3;
const int RP=332748118;

int m,n;
int F[N];
int G[N];

int FP(int a,int k)
{
	int ans=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) ans=1LL*a*ans%mod;
	return ans;
}

int rev[N];
int len=1;
int inv;
int tt;

void getlen(int deg)
{
	while(len<=deg)
	{
		len<<=1;
		tt++;
	}
	return;
}

void getrev()
{
	for(int i=0;i<len;i++)
	rev[i]=((rev[i>>1]>>1)|(i&1)<<(tt-1));
	return;
}

void NTT(int *T,int deg,int opt)
{
	for(int i=0;i<deg;i++)
	if(i<rev[i]) swap(T[i],T[rev[i]]);
	for(int step=1;step<deg;step<<=1)
	{
		int ng=0;
		if(opt==1) ng=FP(PR,(mod-1)/(step<<1));
		if(opt!=1) ng=FP(RP,(mod-1)/(step<<1));
		for(int j=0;j<deg;j+=(step<<1))
		{
			int g=1;
			for(int k=0;k<step;k++)
			{
				int X=T[j+k];
				int Y=T[j+k+step]*1LL*g%mod;
				T[j+k]=(X+Y)%mod;
				T[j+k+step]=(X-Y+mod)%mod;
				g=1LL*g*ng%mod;
			}
		}
	}
	inv=FP(len,mod-2);
	if(opt==1) return;
	for(int i=0;i<len;i++)
	T[i]=1LL*T[i]*inv%mod;
}

void poly_mul(int *F,int *G)
{
	NTT(F,len,1);
	NTT(G,len,1);
	for(int i=0;i<len;i++)
	F[i]=1LL*F[i]*G[i]%mod;
	NTT(F,len,-1);
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++) scanf("%d",&F[i]);
	for(int i=0;i<=m;i++) scanf("%d",&G[i]);
	getlen(n+m);
	getrev();
	for(int i=0;i<=n;i++) F[i]=(F[i]%mod+mod)%mod;
	for(int i=0;i<=m;i++) G[i]=(G[i]%mod+mod)%mod;
	poly_mul(F,G);
	for(int i=0;i<=m+n;i++)
	printf("%d ",F[i]);
	puts("");
	return 0;
}
