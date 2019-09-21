#include<bits/stdc++.h>
using namespace std;

const double eps=1e-12;

double a;
double L,R; 

double F(double x)
{
    return pow(x,a/x-x);
}

double Simpson(double l,double r)
{
	double mid=(l+r)/2.0;
	double ans=(F(l)+F(r)+4.0*F(mid))/6.0;
	return (r-l)*ans;
}

double ASR(double l,double r,double ans)
{
	double mid=(l+r)/2.0;
	double ll=Simpson(l,mid);
	double rr=Simpson(mid,r);
	if(fabs(ll+rr-ans)<eps) return ll+rr;
	else return ASR(l,mid,ll)+ASR(mid,r,rr);
}
int main()
{
	scanf("%lf",&a);
	if(a<0)
	{
		puts("orz");
		return 0;
	}
	L=eps;
	R=20.0;
	printf("%.5lf\n",ASR(L,R,Simpson(L,R)));
	return 0;
}
