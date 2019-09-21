#include<bits/stdc++.h>
using namespace std;

const int N=110;
const double eps=1e-6;

double T[N][N];
bool jud=true;
int n;

void Gauss()
{
	for(int i=1;i<=n;i++)
	{
		int r=i;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(T[r][i])<fabs(T[j][i])) r=j;
		}
		if(r!=i) for(int j=1;j<=n+1;j++) swap(T[i][j],T[r][j]);
		if(fabs(T[i][i])<eps)
		{
			jud=false;
			return;
		}
		for(int j=1;j<=n;j++) if(j!=i)
		{
			double q=T[j][i]/T[i][i];
			for(int k=i+1;k<=n+1;k++)
			{
				T[j][k]-=T[i][k]*q;
			}
		}
	}
	for(int i=1;i<=n;i++)
	T[i][n+1]=T[i][n+1]/T[i][i];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n+1;j++)
	scanf("%lf",&T[i][j]);
	Gauss();
	if(jud==false)
	{
		printf("No Solution\n");
		return 0;
	}
	else for(int i=1;i<=n;i++)
	printf("%.2lf\n",T[i][n+1]);
	return 0;
}
