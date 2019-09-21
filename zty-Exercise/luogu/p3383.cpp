// p3383 线性筛素数
//[数学]
//欧拉筛
//zty111
#include<bits/stdc++.h>
using namespace std;
bool vis[10000010];
int n;
void Linear_Shaker()
{
    int p[n],cnt=0;
    for(int i=2;i<n;i++)
    {
        if(!vis[i])p[++cnt]=i;
        for(int j=1;j<=cnt;j++)
        {
            int v=i*p[j];
            if(v>n)break;
            vis[v]=1;
            if(i%p[j]==0)continue;
        }
    }
}
int main()
{
    int num,t;
    scanf("%d%d",&n,&num);
    Linear_Shaker();
    vis[1]=1;
    for(int i=0;i<num;i++)
    {
        scanf("%d",&t);
        if(!vis[t])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}