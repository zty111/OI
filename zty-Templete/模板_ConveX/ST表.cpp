#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int P=60;

int F[N][P];
int m,n;
int t1;
int t2; 

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&F[i][0]);
	}
	int len=(int)(log(n)/log(2));
	for(int j=1;j<=len;j++)
	for(int i=1;i<=n-(1<<j)+1;i++)
	{
		int tmp=(1<<(j-1))+i;
		F[i][j]=max(F[i][j-1],F[tmp][j-1]);
	}
	while(m--)
	{
		scanf("%d",&t1);
		scanf("%d",&t2);
		len=(int)(log(t2-t1+1)/log(2));
		int ans1=F[t1][len];
		int ans2=F[t2-(1<<len)+1][len];
		printf("%d\n",max(ans1,ans2));
	}
	return 0;
}
