// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int heap[1000010],heap_size;
void push(int d)
{
    int now,nex;
    heap[++heap_size]=d;
    now=heap_size;
    while(now>1)
    {
        nex=now>>1;
        if(heap[now]>=heap[nex])break;
        swap(heap[now],heap[nex]);
        now=nex;
    }
}
void pop()
{
    heap[1]=heap[heap_size--];
    int now=1;
    while((now<<1)<=heap_size)
    {
        int nex=now<<1;
        if(nex+1<=heap_size&&heap[nex+1]<heap[nex])nex++;
        if(heap[nex]<heap[now])swap(heap[now],heap[nex]);
        else break;
        now=nex;
    }
}
int top()
{
    return heap[1];
}
void read(int & x)
{
    x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
}
int main()
{
    int n,opt,a;
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(opt);
        if(opt==1){read(a);push(a);}
        else if(opt==2)printf("%d\n",top());
        else if(opt==3)pop();
    }
    return 0;
}