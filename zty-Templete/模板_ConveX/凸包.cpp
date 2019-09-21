#include<bits/stdc++.h>
using namespace std;

const int N=200010;
const double eps=1e-10;

struct node
{
    double x;
    double y;
}q,A[N];

int top;
int sta[N];

node operator - (node a,node b)
{
    double X=a.x-b.x;
    double Y=a.y-b.y;
    return (node) {X,Y};
}

node operator + (node a,node b)
{
    double X=a.x+b.x;
    double Y=a.y+b.y;
    return (node) {X,Y};
}

double operator * (node a,node b)
{
    return a.x*b.y-a.y*b.x;
}

double len(node a)
{
    return a.x*a.x+a.y*a.y;
}

double operator ^ (node a,node b)
{
	double X=a.x-b.x;
	double Y=a.y-b.y;
	return sqrt(X*X+Y*Y);
}

bool cmp1(node a,node b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

bool cmp2(node a,node b)
{
    if(fabs(a*b)<eps) return len(a)<len(b);
    return a*b>0;
}

void Convex(node *T,int &n)
{
    sort(T+1,T+n+1,cmp1);
    q=T[1];
    sta[top=1]=1;
    for(int i=1;i<=n;i++) T[i]=T[i]-q;
    sort(T+2,T+n+1,cmp2);
    for(int i=2;i<=n;i++)
    {
        while(top>=2)
        {
            node t1=(T[i]-T[sta[top-1]]);
            node t2=(T[sta[top]]-T[sta[top-1]]);
            if(t1*t2<eps) break;
            top--;
        }
        sta[++top]=i;
    }
    for(int i=1;i<=top;i++)
    T[i]=T[sta[i]]+q;
    n=top;
    T[n+1]=T[1];
}

int n;
int tot;
double ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&A[i].x);
        scanf("%lf",&A[i].y);
    }
    Convex(A,n);
    for(int i=1;i<=n;i++)
    ans+=(A[i]^A[i+1]);
	printf("%.2lf\n",ans);
    return 0;
}
