#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x*f;
}
int k,n,p[20],a,ne[20];
double dp[102][1<<15];
int main(){
    k=read();n=read();
    for(int i=1;i<=n;i++){
        p[i]=read();
        while((a=read()))ne[i]|=(1<<(a-1));
    }
    for(int i=k;i>=1;i--)
        for(int s=0;s<(1<<n);s++){
            for(int j=1;j<=n;j++)
                if((s&ne[j])==ne[j])
                    dp[i][s]+=max(dp[i+1][s],dp[i+1][s|(1<<(j-1))]+p[j]);
                else dp[i][s]+=dp[i+1][s];
            dp[i][s]/=n;
        }
    printf("%.6f\n",dp[1][0]);
    return 0;
}