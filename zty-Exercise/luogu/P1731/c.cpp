#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int r[30],h[30],minn=2147483647,n,m;
void dfs(int x,int y,int k,int z)
{  if(y<0) return;
    if(x>m+1) return;
     if(k>=minn) return;
    if(y==0&&x==m+1)
    {  k+=r[1]*r[1];
         if(k<minn) minn=k;
         return;
    }
    if(k+z+r[1]*r[1]>minn) return;
   if(y-(r[x-1])*(r[x-1])*(h[x-1])*z>0) return;
    for(int i=r[x-1]-1;i>=z;i--)
      for(int j=h[x-1]-1;j>=z;j--)
      {
            if(y-i*i*j>=0&&x+1<=m+1)
             {     r[x]=i;
                   h[x]=j;
                    dfs(x+1,y-i*i*j,k+(i*2*j),z-1);
                   h[x]=0;
                   r[x]=0;
             }
      }
}
int main()
{
    scanf("%d%d",&n,&m);
    r[0]=(int)sqrt(n);
    h[0]=(int)sqrt(n);
    dfs(1,n,0,m);
    if(minn==2147483647) printf("%d",0);
      else printf("%d",minn);
    return 0;
}