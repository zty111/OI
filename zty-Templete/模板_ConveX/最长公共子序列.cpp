#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int mp[N];
int dp[N]; 
int a[N];
int b[N];
int ans;
int t1;
int t2;
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		int x=mp[b[i]];
		if(x>dp[ans])
		{
			dp[++ans]=x;
			continue;
		}
		t1=0;
		t2=ans;
		while(t1<t2)
		{
			int mid=(t1+t2)>>1;
			if(dp[mid]>x) t2=mid;
			else t1=mid+1;
		}
		if(x<dp[t1]) dp[t1]=x;
	}
	printf("%d\n",ans);
	return 0;
}
