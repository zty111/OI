#include<bits/stdc++.h>
using namespace std;

const int mod=19260817;
const int N=10010;

int read()
{
	int X=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while( isdigit(ch)) X=(10*X+ch-'0')%mod,ch=getchar();
	return X;
}

int ExGCD(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int ans=ExGCD(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}

int gcd;
int x,y;
int a,b;

int main()
{
	a=read();
	b=read();
	gcd=ExGCD(b,mod,x,y);
	if(gcd!=1)
	{
		puts("Angry!");
		return 0;
	}
	int ans=1;
	ans=1LL*ans*a%mod;
	ans=1LL*ans*x%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
