#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

int heap[N];
int opt;
int tmp;
int num;
int x,n;

void push()
{
	scanf("%d",&x);
	heap[++num]=x;
	for(int i=num,d=i>>1;d;)
	{
		if(heap[i]<heap[d])
		swap(heap[i],heap[d]);
		else break;
		i=d;
		d=i>>1;
	}
}

void pop()
{
	heap[1]=heap[num--];
	for(int i=2,d=1;i<=num;)
	{
		if(heap[i]>heap[i+1])
		if(i<num) i++;
		if(heap[i]<heap[d])
		swap(heap[i],heap[d]);
		else break;
		d=i;
		i=d<<1;
	}
}

int top()
{
	return heap[1];
}

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&opt);
		if(opt==1) push();
		if(opt==2) printf("%d\n",top());
		if(opt==3) pop();
	}
	return 0;
}

