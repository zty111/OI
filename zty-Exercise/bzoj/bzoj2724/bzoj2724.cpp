//参考《算法竞赛进阶指南》
#include<bits/stdc++.h>
using namespace std;
const int u = 40010;
int c[40][40][u],f[40][40],d[40][40],a[u],b[u],fa[u],fb[u],st[40],ed[40];
//c[L][R][b[]]保存L-R中每个b[]的出现次数    f[L][R]保存L-R中的众数  d[L][R]保存最大众数的b[]
//a[]保存原始数据   b[]保存a[]的映射(fb[]的编号)    fa[]保存a[]的排序后的结果   fb[]保存a[]排序+离散化的结果
//st[]保存区间开始位置 ed[]保存区间结束位置
int n,m,t,l,tot,i,j,k,x,y,ans,L,R,cnt,num;
//n原始数据数   m询问数    t分块数t=三次根号n   tot离散化后的总数   l分块长度    i,j,k为编号
//x,y为询问区间     ans答案     L,R为中间分块      cnt出现次数      num为众数的b[]
void prework(){
    //算区间
    t=(int)pow(n*1.0,1.0/3);
    if(t)l=n/t;
    for(i=1;i<=t;i++)st[i]=(i-1)*l+1,ed[i]=i*l;
    if(ed[t]<n)st[t+1]=ed[t]+1,ed[++t]=n;
    //离散化
    memcpy(fa,a,sizeof(a));
    sort(fa+1,fa+1+n);
    for(i=1;i<=n;i++)
        if(i==1||fa[i]!=fa[i-1])fb[++tot]=fa[i];
    for(i=1;i<=n;i++)b[i]=lower_bound(fb+1,fb+1+tot,a[i])-fb;
    //预处理每个区间的众数和众数对应的b[]
    for(i=1;i<=t;i++)
        for(j=i;j<=t;j++){
            for(k=st[i];k<=ed[j];k++)c[i][j][b[k]]++;
            for(k=1;k<=tot;k++)
                if(c[i][j][k]>f[i][j]||c[i][j][k]==f[i][j]&&k<d[i][j])
                    f[i][j]=c[i][j][k],d[i][j]=k;
        }
}
//更新并寻找答案
inline void update(int i){
    c[L][R][b[i]]++;
    if(c[L][R][b[i]]>cnt||c[L][R][b[i]]==cnt&&b[i]<num)cnt=c[L][R][b[i]],num=b[i];//找出众数并更新num
}
int solve(int x,int y){
    int i,l,r;
    if(x>y)swap(x,y);
    for(i=1;i<=t;i++)if(x<=ed[i]){l=i;break;}
    for(i=t;i;i--)if(y>=st[i]){r=i;break;}
    if(l+1<=r-1)L=l+1,R=r-1;else L=R=0;
    cnt=f[L][R],num=d[L][R];//cnt初始为中间区间众数
    if(l==r){//同一个区间
        for(i=x;i<=y;i++)update(i);//将值加入到最大的区间
        for(i=x;i<=y;i++)c[L][R][b[i]]--;//还原
    }
    else{//首+中间+尾
        for(i=x;i<=ed[l];i++)update(i);
        for(i=st[r];i<=y;i++)update(i);
        for(i=x;i<=ed[l];i++)c[L][R][b[i]]--;
        for(i=st[r];i<=y;i++)c[L][R][b[i]]--;
    }
    return fb[num];
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    prework();
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        ans=solve((x+ans-1)%n+1,(y+ans-1)%n+1);//强制在线
        printf("%d\n",ans);
    }
    return 0;
}