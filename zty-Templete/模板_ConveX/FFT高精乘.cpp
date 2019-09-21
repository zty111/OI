#include<bits/stdc++.h>
using namespace std;

const int N=200010;
const double PI=acos(-1.0);

struct Complex
{
	double real;
	double imag;
};

Complex operator + (Complex a,Complex b)
{
	double X=a.real+b.real;
	double Y=a.imag+b.imag;
	return (Complex) {X,Y};
}

Complex operator - (Complex a,Complex b)
{
	double X=a.real-b.real;
	double Y=a.imag-b.imag;
	return (Complex) {X,Y};
}

Complex operator * (Complex a,Complex b)
{
	double X=a.real*b.real-a.imag*b.imag;
	double Y=a.real*b.imag+a.imag*b.real;
	return (Complex) {X,Y};
}

Complex F[N];
Complex G[N];

int rev[N];
int ans[N];
int len=1;
int tt=0;
int m,n;

char s1[N];
char s2[N];

void FFT(Complex *T,int deg,int opt)
{
	for(int i=0;i<deg;i++)
	if(i<rev[i]) swap(T[i],T[rev[i]]);
	for(int step=1;step<deg;step<<=1)
	{
		Complex Wn;
		double q=PI/step;
		Wn.real=cos(q);
		Wn.imag=sin(q)*opt;
		for(int j=0;j<deg;j+=(step<<1))
		{
			Complex w;
			w.real=1.0;
			w.imag=0.0;
			for(int k=0;k<step;k++,w=w*Wn)
			{
				Complex X=T[j+k];
				Complex Y=T[j+k+step]*w;
				T[j+k]=X+Y;
				T[j+k+step]=X-Y;
			}
		}
	}
}

void getlen()
{
	int deg=n+m;
	while(len<=deg)
	{
		len<<=1;
		tt++;
	}
}

void getrev()
{
	for(int i=0;i<len;i++)
	rev[i]=((rev[i>>1]>>1)|((i&1)<<(tt-1)));
}

void calc_FFT()
{
    FFT(F,len,1);
    FFT(G,len,1);
    for(int i=0;i<=len;i++) F[i]=F[i]*G[i];
    FFT(F,len,-1);
}

int main()
{
	scanf("%d",&n);
	m=n;
	getlen();
	getrev();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=n;i;i--) F[n-i].real=1.0*s1[i]-'0';
	for(int i=m;i;i--) G[n-i].real=1.0*s2[i]-'0';
	calc_FFT();
    for(int i=0;i<=len;i++) F[i].real=(F[i].real/len+0.5);
    for(int i=0;i<len;i++)
    {
    	ans[i]+=F[i].real;
    	ans[i+1]+=ans[i]/10;
    	ans[i]%=10;
	}
	bool jud=true;
	for(int i=m+n;~i;i--)
	{
		if(!ans[i]&&jud) continue;
		else
		{
			printf("%d",ans[i]);
			jud=false;
		}
	}
	puts("");
	return 0;
}
