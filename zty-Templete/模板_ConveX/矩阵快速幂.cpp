#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
long long n,p;

struct Matrix
{
    int T[101][101];	
}E,P;

inline Matrix mul(Matrix X,Matrix Y)
{
    Matrix Z;
    memset(Z.T,0,sizeof(Z.T));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    Z.T[i][j]=(1LL*Z.T[i][j]%mod+1LL*X.T[i][k]*Y.T[k][j]%mod)%mod;
    return Z;
}

Matrix pow(Matrix M,long long k)
{
    Matrix ans=E;
    for(;k;k>>=1,M=mul(M,M))
        if(k&1) ans=mul(ans,M);
    return ans;
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&p);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",&P.T[i][j]);
    for(int i=1;i<=n;i++)
    E.T[i][i]=1;
    Matrix ans=pow(P,p);
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=n;j++)
		printf("%d ",ans.T[i][j]%mod);
    	puts("");
    }
    return 0;
}
