#include<bits/stdc++.h>
using namespace std;

const int N=50000010;
const int M=100000010;

int p[N];
int ans;
int len;
char a[N];
char s[M];

void manacher()
{
	int mas=0;
	int mid=0;
	for(int i=1;i<len;i++)
	{
		if(i<mas)
		{
			int t1=p[mid]+mid-i;
			int t2=p[mid*2-i];
			p[i]=min(t1,t2);
		}
		else p[i]=1;
		while(true)
		{
			int t1=i+p[i];
			int t2=i-p[i];
			if(s[t1]!=s[t2]) break;
			p[i]++;
		}
		if(p[i]+i>mas)
		{
			mid=i;
			mas=mid+p[i];
		}
	}
}

void init()
{
	s[0]='!';
	s[1]='#';
	for(int i=0;i<len;i++)
	{
		s[i*2+2]=a[i];
		s[i*2+3]='#';
	}
	len=len*2+2;
	s[len]=0;
}

int main()
{
	scanf("%s",a);
	len=strlen(a);
	init();
	manacher();
	for(int i=0;i<len;i++)
	ans=max(ans,p[i]-1);
	printf("%d\n",ans);
	return 0;
}
