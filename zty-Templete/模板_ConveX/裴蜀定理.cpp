#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
	if(y<0) y=-y;
	if(x<0) x=-x;
	if(!y) return x;
	return gcd(y,x%y);
}

int ans;
int tmp;
int n;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tmp);
		ans=gcd(tmp,ans);
	}
	printf("%d\n",ans);
	return 0;
}
