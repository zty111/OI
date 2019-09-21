#include<bits/stdc++.h>
using namespace std;

const int N=20000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const int RP=332748118;
const int PR=3;

int FP(int a,int k)
{
	int ans=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) ans=1LL*a*ans%mod;
	return ans;
}

int rev[N];
int len;
int inv;
int tt;

void NTT(int *T,int deg,int opt)
{
	for(int i=0;i<deg;i++)
	{
		if(i>=rev[i]) continue;
		swap(T[i],T[rev[i]]);
	}
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
	return;
}

void getlen(int deg)
{
	len=1;
	tt=0;
	while(len<=deg)
	{
		len<<=1;
		tt++;
	}
	return;
}

void getrev(int len)
{
	for(int i=0;i<len;i++)
	rev[i]=((rev[i>>1]>>1)|((i&1)<<(tt-1)));
	return;
}

void poly_mul(int *F,int *G,int deg)
{
	getlen(deg);
	getrev(len);
	NTT(F,len,1);
	NTT(G,len,1);
	for(int i=0;i<len;i++) F[i]=1LL*F[i]*G[i]%mod;
	NTT(F,len,-1);
	for(int i=0;i<len;i++) F[i]=1LL*F[i]*inv%mod;
	return;
}

int F[N];
int G[N];
int I[N];

void poly_inv(int *F,int *G,int deg)
{
	if(deg==1)
	{
		G[0]=FP(F[0],mod-2);
		return;
	}
	poly_inv(F,G,(deg+1)>>1);
	getlen(deg<<1);
	getrev(len);
	for(int i=0;i<len;i++)
	{
		if(i<deg) I[i]=F[i];
		else I[i]=0;
	}
	NTT(I,len,1);
	NTT(G,len,1);
	for(int i=0;i<len;i++)
	G[i]=(2-1LL*G[i]*I[i]%mod+mod)%mod*G[i]%mod;
	NTT(G,len,-1);
	for(int i=0;i<deg;i++) G[i]=1LL*G[i]*FP(len,mod-2)%mod;
	for(int i=deg;i<len;i++) G[i]=0;
}

void read(int *T,int l)
{
 	for(int i=0;i<l;i++)
	scanf("%d",&T[i]);
	return;
}

void write(int *T,int l)
{
	for(int i=0;i<l;i++)
	printf("%d ",T[i]);
	puts("");
	return;
}

int n;

int main()
{
	scanf("%d",&n);
	read(F,n);
	poly_inv(F,G,n);
	write(G,n);
	return 0; 
}
