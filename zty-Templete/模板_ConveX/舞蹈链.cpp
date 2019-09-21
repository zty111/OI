// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

const int N=2010;
const int NN=1002010;

int n,m,tmp;
int size,cnt;
int ans[N];
int H[N],S[N];

struct node
{
    int u,d,l,r;
    int col,row;
}T[NN];

void init(int x,int y)
{
    memset(H,-1,sizeof(H));
    for(int i=0;i<=y;i++)
    {
        T[i].u=i;
        T[i].d=i;
        T[i].l=i-1;
        T[i].r=i+1;
        T[i].col=i;
        S[i]=0;
    }
    T[0].l=y;
    T[y].r=0;
    size=y;
    return;
}

void push(int x,int y)
{
    size++;
    T[size].d=T[y].d;
    T[size].u=y;
    T[T[size].d].u=size;
    T[T[size].u].d=size;
    T[size].row=x;
    T[size].col=y;
    S[y]++;
    if(H[x]<0)
    {
        H[x]=size;
        T[size].l=size;
        T[size].r=size;
    }
    else
    {
        T[size].l=H[x];
        T[size].r=T[H[x]].r;
        T[T[size].r].l=size;
        T[T[size].l].r=size;
    }
}

void del(int y)
{
    T[T[y].l].r=T[y].r;
    T[T[y].r].l=T[y].l;
    for(int i=T[y].u;i!=y;i=T[i].u)
    for(int j=T[i].r;j!=i;j=T[j].r)
    {
        T[T[j].u].d=T[j].d;
        T[T[j].d].u=T[j].u;
        S[T[j].col]--;
    }
    return;
}

void back(int y)
{
    for(int i=T[y].u;i!=y;i=T[i].u)
    for(int j=T[i].r;j!=i;j=T[j].r)
    {
        T[T[j].u].d=j;
        T[T[j].d].u=j;
        S[T[j].col]++;
    }
    T[T[y].l].r=y;
    T[T[y].r].l=y;
    return;
}

bool dancing()
{
    if(T[0].r==0)
    {
        return true;
    }
    int y=T[0].r;
    for(int i=T[0].r;i;i=T[i].r)
    {
        if(S[i]<S[y]) y=i;
    }
    del(y);
    for(int i=T[y].u;i!=y;i=T[i].u)
    {
        for(int j=T[i].r;j!=i;j=T[j].r)
        {
            del(T[j].col);
        }
        ans[++cnt]=T[i].row;
        if(dancing())
        {
            return true;
        }
        ans[cnt--]=0;
        for(int j=T[i].r;j!=i;j=T[j].r)
        {
            back(T[j].col);
        }
    }
    back(y);
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    init(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&tmp);
            if(tmp) push(i,j);
        }
    }
    if(dancing())
    {
        for(int i=1;i<=cnt;i++)
        printf("%d ",ans[i]);
        puts("");
    }
    else puts("No Solution!");
    return 0;
}
