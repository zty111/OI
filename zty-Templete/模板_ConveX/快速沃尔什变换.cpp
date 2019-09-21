#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int mod=998244353;

int read()
{
	int X=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) X=10*X+ch-'0',ch=getchar();
	return X*f;
}

int FP(int a,int k)
{
	int ans=1;
	for(;k;k>>=1,a=1LL*a*a%mod)
	if(k&1) ans=1LL*a*ans%mod;
	return ans;
}

void CP(int &a,int b) {if((a+=b)>=mod) a-=mod;}
void CS(int &a,int b) {if((a-=b)<0)    a+=mod;}
int P(int a,int b) {if(a+b>=mod) return a+b-mod; return a+b;}
int S(int a,int b) {if(a-b<0)    return a-b+mod; return a-b;}

void FMT_or(int *F,int deg,int opt)
{
	for(int step=0;step<deg;step++)
	for(int j=0;j<(1<<deg);j++)
	if(j>>step&1)
	{
		int k=j^1<<step;
		if(opt^1) CP(F[j],mod-F[k]);
		else CP(F[j],F[k]);
	}
	return;
}

void FMT_and(int *F,int deg,int opt)
{
	for(int step=0;step<deg;step++)
	for(int j=(1<<deg)-1;~j;j--)
	if(~j>>step&1)
	{
		int k=j|1<<step;
		if(opt^1) CP(F[j],mod-F[k]);
		else CP(F[j],F[k]);
	}
	return;
}

void FWT(int *F,int deg,int opt)
{
	for(int step=1;step*2<=(1<<deg);step<<=1)
	for(int j=0;j<(1<<deg);j+=2*step)
	for(int k=0;k<step;k++)
	{
		int X=F[j+k];
		int Y=F[j+k+step];
		if(opt^1)
		{
			F[j+k]=1LL*FP(2,mod-2)*P(X,Y)%mod;
			F[j+k+step]=1LL*FP(2,mod-2)*S(X,Y)%mod;
		}
		else
		{
			F[j+k]=P(X,Y);
			F[j+k+step]=S(X,Y);
		}
	}
}

int n,len;
int F1[N],F2[N],F3[N];
int G1[N],G2[N],G3[N];
int H1[N],H2[N],H3[N];

void Or()
{
	FMT_or(F1,n,1);
	FMT_or(G1,n,1);
	for(int i=0;i<len;i++) H1[i]=1LL*F1[i]*G1[i]%mod;
	FMT_or(H1,n,-1);
}

void And()
{
	FMT_and(F2,n,1);
	FMT_and(G2,n,1);
	for(int i=0;i<len;i++) H2[i]=1LL*F2[i]*G2[i]%mod;
	FMT_and(H2,n,-1);
}

void Xor()
{
	FWT(F3,n,1);
	FWT(G3,n,1);
	for(int i=0;i<len;i++) H3[i]=1LL*F3[i]*G3[i]%mod;
	FWT(H3,n,-1);
}

int main()
{
	scanf("%d",&n);
	len=1<<n;
	for(int i=0;i<len;i++) F1[i]=F2[i]=F3[i]=read();
	for(int i=0;i<len;i++) G1[i]=G2[i]=G3[i]=read();
	Or();
	And();
	Xor();
	for(int i=0;i<len;i++) printf("%d ",H1[i]);puts("");
	for(int i=0;i<len;i++) printf("%d ",H2[i]);puts("");
	for(int i=0;i<len;i++) printf("%d ",H3[i]);puts("");
	return 0;
}
