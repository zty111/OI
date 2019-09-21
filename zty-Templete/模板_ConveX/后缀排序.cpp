#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

int SA[N];
int rnk[N];
int het[N];
int bin[N];
int a[N];
int b[N];
int m,n;
char s[N];

void getSA()
{
	for(int i=1;i<=n;i++) bin[a[i]=s[i]-'0'+1]++;
	for(int i=1;i<=m;i++) bin[i]+=bin[i-1];
	for(int i=n;i>=1;i--) SA[bin[a[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int tmp=0;
		for(int i=n-k+1;i<=n;i++) b[++tmp]=i;
		for(int i=1;i<=n;i++) if(SA[i]>=k+1) b[++tmp]=SA[i]-k;
		for(int i=1;i<=m;i++) bin[i]=0;
		for(int i=1;i<=n;i++) bin[a[b[i]]]++;
		for(int i=1;i<=m;i++) bin[i]+=bin[i-1];
		for(int i=n;i>=1;i--) SA[bin[a[b[i]]]--]=b[i];
		swap(a,b);
		tmp=0;
		for(int i=1;i<=n;i++)
		{
			if(b[SA[i]]!=b[SA[i-1]]) a[SA[i]]=++tmp;
			else if(b[SA[i]+k]!=b[SA[i-1]+k]) a[SA[i]]=++tmp;
			else a[SA[i]]=tmp;
		}
		if(tmp>=n) break;
		m=tmp;
	}
	for(int i=1;i<=n;i++) rnk[SA[i]]=i;
	for(int i=1,tmp=0;i<=n;i++)
	{
		if(tmp) tmp--;
		while(s[i+tmp]==s[SA[rnk[i]-1]+tmp]) tmp++;
		het[rnk[i]]=tmp;
	}
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	m=128;
	getSA();
	for(int i=1;i<=n;i++)
	printf("%d ",SA[i]);
	puts("");
	return 0;
}
