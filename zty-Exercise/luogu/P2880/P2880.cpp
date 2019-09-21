#include<bits/stdc++.h>
using namespace std;
int n,f[50010][16],p[50010][16],a[50010],q,l,r;
void ST_prework(){
    for(int i=1;i<=n;i++)f[i][0]=a[i],p[i][0]=a[i];
    int t=log(n)/log(2)+1;
    for(int j=1;j<t;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),
            p[i][j]=min(p[i][j-1],p[i+(1<<(j-1))][j-1]);
}
int ST_query(int l,int r){
    int k=log(r-l+1)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k])-min(p[l][k],p[r-(1<<k)+1][k]);
}
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
int main(){
    n=read();q=read();
    for(int i=1;i<=n;i++)a[i]=read();
    ST_prework();
    for(int i=1;i<=q;i++){
        l=read();r=read();
        printf("%d\n",ST_query(l,r));
    }
    return 0;
}