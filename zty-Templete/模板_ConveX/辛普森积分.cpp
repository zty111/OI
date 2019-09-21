#include<bits/stdc++.h>
using namespace std;

const double eps=1e-12;

double a,b;
double c,d;
double L,R; 

double F(double x)
{
	double t1=c*x+d;
	double t2=a*x+b;
	return t1/t2;
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
	scanf("%lf",&b);
	scanf("%lf",&c);
	scanf("%lf",&d);
	scanf("%lf",&L);
	scanf("%lf",&R);
	printf("%.6lf\n",ASR(L,R,Simpson(L,R)));
}
