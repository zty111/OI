#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

char s1[N];
char s2[N];
int len1;
int len2;
int nxt[N];

void getnxt()
{
	for(int i=1,j=0;i<len2;i++)
	{
		while(s2[i]!=s2[j]&&j) j=nxt[j];
		if(s2[i]==s2[j]) nxt[i+1]=++j;
		else nxt[i+1]=0;
	}
	return;
}

int main()
{
	scanf("%s",s1);
	scanf("%s",s2);
	len1=strlen(s1);
	len2=strlen(s2);
	getnxt();
	for(int i=0,j=0;i<len1;i++)
	{
		while(s1[i]!=s2[j]&&j) j=nxt[j];
		if(s1[i]==s2[j]) j++;
		if(j==len2) printf("%d\n",i+2-len2);
	}
	for(int i=1;i<=len2;i++)
	printf("%d ",nxt[i]);
	printf("\n");
	return 0;
}
